#include <yara.h>
#include <stdio.h>
#include "util.h"
#include "defects4cpp.h"

int main(int argc, char** argv)
{
  yr_initialize();
  int index = defects4cpp_test_index();
  switch (index) {
      case 156:
  assert_true_rule_file(
      "import \"pe\" \
      rule test { \
        condition: \
          pe.imports(\"KERNEL32.dll\", \"DeleteCriticalSection\") \
      }",
      "tests/data/tiny");
          break;
      case 157:
  assert_true_rule_file(
      "import \"pe\" \
      rule test { \
        condition: \
          pe.imports(\"KERNEL32.dll\", \"DeleteCriticalSection\") \
      }",
      "tests/data/tiny-idata-51ff");
          break;
      case 158:
  assert_false_rule_file(
      "import \"pe\" \
      rule test { \
        condition: \
          pe.imports(\"KERNEL32.dll\", \"DeleteCriticalSection\") \
      }",
      "tests/data/tiny-idata-5200");
          break;
      case 159:
  assert_true_rule_file(
      "import \"pe\" \
      rule test { \
        condition: \
          pe.number_of_imports == 2 \
      }",
      "tests/data/tiny");
          break;
      case 160:
  assert_true_rule_file(
      "import \"pe\" \
      rule test { \
        condition: \
          pe.number_of_sections == 7 \
      }",
      "tests/data/tiny");
          break;
      case 161:
  assert_true_rule_file(
      "import \"pe\" \
      rule test { \
        condition: \
          pe.entry_point == 0x14E0 \
      }",
      "tests/data/tiny");
          break;
      case 162:
  assert_true_rule_file(
      "import \"pe\" \
      rule test { \
        condition: \
          pe.linker_version.major == 2 and \
          pe.linker_version.minor == 26 \
      }",
      "tests/data/tiny");
          break;
      case 163:
  assert_true_rule_file(
      "import \"pe\" \
      rule test { \
        condition: \
          pe.sections[0].name == \".text\" and \
          pe.sections[1].name == \".data\" and \
          pe.sections[2].name == \".rdata\" and \
          pe.sections[3].name == \".bss\" and \
          pe.sections[4].name == \".idata\" and \
          pe.sections[5].name == \".CRT\" and \
          pe.sections[6].name == \".tls\" \
      }",
      "tests/data/tiny");
          break;
      case 164:
  #if defined(HAVE_LIBCRYPTO) || \
      defined(HAVE_WINCRYPT_H) || \
      defined(HAVE_COMMONCRYPTO_COMMONCRYPTO_H)

  assert_true_rule_file(
      "import \"pe\" \
      rule test { \
        condition: \
          pe.imphash() == \"1720bf764274b7a4052bbef0a71adc0d\" \
      }",
      "tests/data/tiny");
  #endif
          break;
      case 165:
  assert_true_rule_file(
      "import \"pe\" \
      rule test { \
        condition: \
          pe.section_index(\".text\") == 0 \
      }",
      "tests/data/tiny");
          break;
      case 166:
  assert_true_rule_file(
      "import \"pe\" \
      rule test { \
        condition: \
          pe.section_index(pe.entry_point) == 0 \
      }",
      "tests/data/tiny");
          break;
      case 167:
  assert_true_rule_file(
      "import \"pe\" \
      rule test { \
        condition: \
          pe.is_32bit() and not pe.is_64bit() \
      }",
      "tests/data/tiny");
          break;
      case 168:
  assert_true_rule_file(
      "import \"pe\" \
      rule test { \
        condition: \
          pe.checksum == 0xA8DC \
      }",
      "tests/data/tiny");
          break;
      case 169:
  assert_true_rule_file(
      "import \"pe\" \
      rule test { \
        condition: \
          pe.checksum == pe.calculate_checksum() \
      }",
      "tests/data/tiny");
          break;
      case 170:
  assert_true_rule_file(
      "import \"pe\" \
      rule test { \
        condition: \
          pe.overlay.offset == 0x8000 and pe.overlay.size == 7 \
      }",
      "tests/data/tiny-overlay");
          break;
      case 171:
  assert_true_rule_file(
      "import \"pe\" \
      rule test { \
        condition: \
         pe.overlay.size == 0 \
      }",
      "tests/data/tiny");
          break;
      case 172:
  assert_false_rule_file(
      "import \"pe\" \
      rule test { \
        condition: \
          pe.checksum == pe.calculate_checksum() \
      }",
      "tests/data/tiny-idata-51ff");
          break;
  }
  yr_finalize();
  return 0;
}
