#!/bin/sh

cd "$(dirname "${0}")"

FUZZY_TESTING_ENABLED=0
if [ "${NDPI_DISABLE_FUZZY}" = "1" ]; then
   FUZZY_TESTING_ENABLED=0
fi

#Remember: valgrind and *SAN are incompatible!
CMD_PREFIX="${CMD_PREFIX}"
if [ "${NDPI_TESTS_WINE}" = "1" ]; then
   CMD_PREFIX="wine"
elif [ "${NDPI_TESTS_VALGRIND}" = "1" ]; then
   CMD_PREFIX="valgrind -q --leak-check=full"
fi

CMD_DIFF="$(which diff)"
CMD_WDIFF="$(which wdiff)"
CMD_COLORDIFF="$(which colordiff)"

EXE_SUFFIX=
PCRE_ENABLED=0
PCRE_PCAPS="WebattackRCE.pcap"
GCRYPT_PCAPS="gquic.pcap quic-23.pcap quic-24.pcap quic-27.pcap quic-28.pcap quic-29.pcap quic-mvfst-22.pcap quic-mvfst-27.pcapng quic-mvfst-exp.pcap quic_q50.pcap quic_t50.pcap quic_t51.pcap quic_0RTT.pcap quic_interop_V.pcapng quic-33.pcapng doq.pcapng doq_adguard.pcapng dlt_ppp.pcap os_detected.pcapng quic_frags_ch_out_of_order_same_packet_craziness.pcapng quic_frags_ch_in_multiple_packets.pcapng quic-v2-00.pcapng"
READER="${CMD_PREFIX} ../example/ndpiReader${EXE_SUFFIX} -p ../example/protos.txt -c ../example/categories.txt -r ../example/risky_domains.txt -j ../example/ja3_fingerprints.csv -S ../example/sha1_fingerprints.csv"

RC=0
PCAPS=`cd pcap; /bin/ls *.pcap *.pcapng *.cap`

if [ ! -x "../example/ndpiReader${EXE_SUFFIX}" ]; then
  echo "$0: Missing $(realpath ../example/ndpiReader${EXE_SUFFIX})"
  echo "$0: Run ./configure and make first"
  exit 1
fi

fuzzy_testing() {
    if [ -f ../fuzz/fuzz_ndpi_reader ]; then
	../fuzz/fuzz_ndpi_reader -max_total_time="${MAX_TOTAL_TIME:-592}" -print_pcs=1 -workers="${FUZZY_WORKERS:-0}" -jobs="${FUZZY_JOBS:-0}" pcap/
    fi
}

build_results() {
    for f in $PCAPS; do
	#echo $f
	# create result files if not present
	if [ ! -f result/$f.out ]; then
	    CMD="$READER -q -t -i pcap/$f -w result/$f.out -v 2"
	    $CMD
	fi
    done
}

check_results() {
	for f in $PCAPS; do
	    if [ -n "$*" ]; then
	    	SKIP_PCAP=1
		for i in $* ; do [ "$f" = "$i" ] && SKIP_PCAP=0 && break ; done
		[ $SKIP_PCAP = 1 ] && continue
	    fi
	    SKIP_PCAP=0
	    if [ $PCRE_ENABLED -eq 0 ]; then
	      for p in $PCRE_PCAPS; do
	        if [ $f = $p ]; then
	          SKIP_PCAP=1
	          break
	        fi
	      done
	    fi
	    if [ $SKIP_PCAP -eq 1 ]; then
	        printf "%-32s\tSKIPPED\n" "$f"
	        continue
	    fi

	if [ -f result/$f.out ]; then
	    CMD="$READER -q -t -i pcap/$f -w /tmp/reader.out -v 2"
	    $CMD
	    CMD_RET=$?
	    if [ $CMD_RET -eq 0 ]; then
	      NUM_DIFF=`${CMD_DIFF} result/$f.out /tmp/reader.out | wc -l`
	    else
	      printf "%-48s\tERROR (ndpiReader${EXE_SUFFIX} exit code: ${CMD_RET})\n" "$f"
	      RC=$(( RC + 1 ))
	      continue
	    fi

		if [ $NUM_DIFF -eq 0 ]; then
		  printf "%-48s\tOK\n" "$f"
		else
		  printf "%-48s\tERROR\n" "$f"
		  echo "$CMD [old vs new]"
		  ${CMD_DIFF} result/$f.out /tmp/reader.out
		  if [ ! -z "${CMD_COLORDIFF}" -a ! -z "${CMD_WDIFF}" ]; then
		    ${CMD_WDIFF} -n -3 result/$f.out /tmp/reader.out | sort | uniq | ${CMD_COLORDIFF}
		  fi
		  RC=$(( RC + 1 ))
	    fi

	    /bin/rm -f /tmp/reader.out
	fi
    done
}

if [ $FUZZY_TESTING_ENABLED -eq 1 ]; then
    fuzzy_testing
fi
build_results
check_results $*

test ${RC} -ne 0 && printf '%s: %s\n' "${0}" "${RC} pcap(s) failed"

exit $RC
