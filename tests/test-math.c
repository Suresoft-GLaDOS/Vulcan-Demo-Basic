#include <yara.h>
#include <stdio.h>
#include "util.h"
#include "defects4cpp.h"

int main(int argc, char** argv)
{
  yr_initialize();
  int index = defects4cpp_test_index();
  switch (index) {
      case 154:
  assert_true_rule_blob(
      "import \"math\" \
      rule test { \
        condition: \
          math.min(0, 1) == 0 \
      }",
      "A");
          break;
      case 155:
  assert_true_rule_blob(
      "import \"math\" \
      rule test { \
        condition: \
          math.max(0, 1) == 1 \
      }",
      "A");
          break;
  }
  yr_finalize();
  return 0;
}
