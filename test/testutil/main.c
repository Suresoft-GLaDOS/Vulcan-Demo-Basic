/*
 * Copyright 2016-2018 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#include "../testutil.h"
#include "output.h"
#include "tu_local.h"
#include <signal.h>
static struct sigaction dpp_gcov_sigaction;
static struct sigaction dpp_orig_sigaction;
void dpp_sighandler(int signum) {
#ifdef DPP_ENABLE_GCOV
  __gcov_flush();
#endif
  sigaction(SIGSEGV, &dpp_orig_sigaction, NULL);
  raise(SIGSEGV);
}


int main(int argc, char *argv[])
{
    {
   dpp_gcov_sigaction.sa_handler = dpp_sighandler;
   sigemptyset(&dpp_gcov_sigaction.sa_mask);
   dpp_gcov_sigaction.sa_flags = 0;
   sigaction(SIGSEGV, &dpp_gcov_sigaction, &dpp_orig_sigaction);
    }
    int ret = EXIT_FAILURE;

    test_open_streams();

    if (!global_init()) {
        test_printf_stderr("Global init failed - aborting\n");
        return ret;
    }

    if (!setup_test_framework(argc, argv))
        goto end;

    if (setup_tests()) {
        ret = run_tests(argv[0]);
        cleanup_tests();
        opt_check_usage();
    } else {
        opt_help(test_get_options());
    }
end:
    ret = pulldown_test_framework(ret);
    test_close_streams();
    return ret;
}
