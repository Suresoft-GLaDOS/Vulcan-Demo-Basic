/*
Copyright (c) 2016. The YARA Authors. All Rights Reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software without
specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <yara.h>
#include <stdio.h>
#undef NDEBUG
#include <assert.h>
#include "defects4cpp.h"

int err = 0;

#define CHECK_SIZE(expr,size)                          \
  do                                                   \
  {                                                    \
    printf("sizeof("#expr") = %zd ...", sizeof(expr)); \
    if (sizeof(expr) == size)                          \
    {                                                  \
      puts("ok");                                      \
    }                                                  \
    else                                               \
    {                                                  \
      printf("expected %d\n", size);                   \
      err = 1;                                         \
    }                                                  \
  } while (0);

#define CHECK_OFFSET(expr,offset,subexpr)             \
  do                                                  \
  {                                                   \
    printf("offsetof("#expr", "#subexpr") = %zd ...", \
           offsetof(expr, subexpr));                  \
    if (offsetof(expr, subexpr) == offset)            \
    {                                                 \
      puts("ok");                                     \
    }                                                 \
    else                                              \
    {                                                 \
      printf("expected %d\n", offset);                \
    }                                                 \
  } while (0)

int main (int argc, char **argv)
{
  int index = defects4cpp_test_index();
  switch (index) {
      case 1:
  CHECK_SIZE(YR_NAMESPACE, 4 * YR_MAX_THREADS + 8);
          break;
      case 2:
  CHECK_OFFSET(YR_NAMESPACE, 4 * YR_MAX_THREADS, name);
          break;
      case 3:
  CHECK_SIZE(YR_META, 32);
          break;
      case 4:
  CHECK_OFFSET(YR_META, 8,  integer);
          break;
      case 5:
  CHECK_OFFSET(YR_META, 16, identifier);
          break;
      case 6:
  CHECK_OFFSET(YR_META, 24, string);
          break;
      case 7:
  CHECK_SIZE(YR_MATCHES, 24);
          break;
      case 8:
  CHECK_OFFSET(YR_MATCHES, 8,  head);
          break;
      case 9:
  CHECK_OFFSET(YR_MATCHES, 16, tail);
          break;
      case 10:
  CHECK_SIZE(YR_STRING, 56 + 2 * 24 /* YR_MATCHES */ * YR_MAX_THREADS);
          break;
      case 11:
  CHECK_OFFSET(YR_STRING, 4,  length);
          break;
      case 12:
  CHECK_OFFSET(YR_STRING, 8,  identifier);
          break;
      case 13:
  CHECK_OFFSET(YR_STRING, 16, string);
          break;
      case 14:
  CHECK_OFFSET(YR_STRING, 24, chained_to);
          break;
      case 15:
  CHECK_OFFSET(YR_STRING, 32, rule);
          break;
      case 16:
  CHECK_OFFSET(YR_STRING, 40, chain_gap_min);
          break;
      case 17:
  CHECK_OFFSET(YR_STRING, 44, chain_gap_max);
          break;
      case 18:
  CHECK_OFFSET(YR_STRING, 48, fixed_offset);
          break;
      case 19:
  CHECK_SIZE(YR_RULE, 64 + 12 * YR_MAX_THREADS);
          break;
      case 20:
  CHECK_OFFSET(YR_RULE, 4,                           t_flags);
          break;
      case 21:
  CHECK_OFFSET(YR_RULE, 8 + 4 * YR_MAX_THREADS,      identifier);
          break;
      case 22:
  CHECK_OFFSET(YR_RULE, 8 + 4 * YR_MAX_THREADS + 8,  tags);
          break;
      case 23:
  CHECK_OFFSET(YR_RULE, 8 + 4 * YR_MAX_THREADS + 16, metas);
          break;
      case 24:
  CHECK_OFFSET(YR_RULE, 8 + 4 * YR_MAX_THREADS + 24, strings);
          break;
      case 25:
  CHECK_OFFSET(YR_RULE, 8 + 4 * YR_MAX_THREADS + 32, ns);
          break;
      case 26:
  CHECK_SIZE(YR_EXTERNAL_VARIABLE, 24);
          break;
      case 27:
  CHECK_OFFSET(YR_EXTERNAL_VARIABLE, 8,  value.i);
          break;
      case 28:
  CHECK_OFFSET(YR_EXTERNAL_VARIABLE, 8,  value.f);
          break;
      case 29:
  CHECK_OFFSET(YR_EXTERNAL_VARIABLE, 8,  value.s);
          break;
      case 30:
  CHECK_OFFSET(YR_EXTERNAL_VARIABLE, 16, identifier);
          break;
      case 31:
  CHECK_SIZE(YR_AC_MATCH, 40);
          break;
      case 32:
  CHECK_OFFSET(YR_AC_MATCH, 8,  string);
          break;
      case 33:
  CHECK_OFFSET(YR_AC_MATCH, 16, forward_code);
          break;
      case 34:
  CHECK_OFFSET(YR_AC_MATCH, 24, backward_code);
          break;
      case 35:
  CHECK_OFFSET(YR_AC_MATCH, 32, next);
          break;
      case 36:
  CHECK_SIZE(YARA_RULES_FILE_HEADER, 48);
          break;
      case 37:
  CHECK_OFFSET(YARA_RULES_FILE_HEADER, 0, rules_list_head);
          break;
      case 38:
  CHECK_OFFSET(YARA_RULES_FILE_HEADER, 8, externals_list_head);
          break;
      case 39:
  CHECK_OFFSET(YARA_RULES_FILE_HEADER, 16, code_start);
          break;
      case 40:
  CHECK_OFFSET(YARA_RULES_FILE_HEADER, 24, ac_match_table);
          break;
      case 41:
  CHECK_OFFSET(YARA_RULES_FILE_HEADER, 32, ac_transition_table);
          break;
      case 42:
  CHECK_SIZE(SIZED_STRING, 12);
          break;
      case 43:
  CHECK_OFFSET(SIZED_STRING, 4, flags);
          break;
      case 44:
  CHECK_OFFSET(SIZED_STRING, 8, c_string);
          break;
  }

  return err;
}
