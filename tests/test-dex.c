#include <yara.h>
#include "util.h"
#include "blob.h"
#include "defects4cpp.h"

int main(int argc, char** argv)
{
  yr_initialize();
  int index = defects4cpp_test_index();
  switch (index) {
      case 105:
  assert_true_rule_blob(
      "import \"dex\" rule test { condition: dex.header.magic == \
        dex.DEX_FILE_MAGIC_035 }",
      DEX_FILE);
          break;
      case 106:
  assert_true_rule_blob(
      "import \"dex\" rule test { condition: dex.header.checksum == \
        0x3F9C602F }",
      DEX_FILE);
          break;
      case 107:
  assert_true_rule_blob(
      "import \"dex\" rule test { condition: dex.header.data_size == \
        0x18C }",
      DEX_FILE);
          break;
      case 108:
  assert_true_rule_blob(
      "import \"dex\" rule test { condition: dex.string_ids[0].value ==\
      \"<clinit>\" }",
      DEX_FILE);
          break;
      case 109:
  assert_true_rule_blob(
      "import \"dex\" rule test { condition: dex.string_ids[8].value == \
        \"com.google.helloyara\" }",
      DEX_FILE);
          break;
      case 110:
  assert_true_rule_blob(
      "import \"dex\" rule test { condition: dex.type_ids[0].descriptor_idx == \
        0x2 }",
      DEX_FILE);
          break;
      case 111:
  assert_true_rule_blob(
      "import \"dex\" rule test { condition: dex.proto_ids[0].shorty_idx == \
        0x6 }",
      DEX_FILE);
          break;
      case 112:
  assert_true_rule_blob(
      "import \"dex\" rule test { condition: dex.field_ids[0].class_idx == \
        0x1 }",
      DEX_FILE);
          break;
      case 113:
  assert_true_rule_blob(
      "import \"dex\" rule test { condition: dex.method_ids[0].class_idx == \
        0x1 }",
      DEX_FILE);
          break;
      case 114:
  assert_true_rule_blob(
      "import \"dex\" rule test { condition: dex.class_defs[0].class_idx == \
        0x1 }",
      DEX_FILE);
          break;
      case 115:
  assert_true_rule_blob(
      "import \"dex\" rule test { condition: dex.number_of_fields == 2 }",
      DEX_FILE);
          break;
      case 116:
  assert_true_rule_blob(
      "import \"dex\" rule test { condition: dex.field[0].class_name == \
        \"Lcom/android/tools/ir/server/AppInfo;\" }",
      DEX_FILE);
          break;
      case 117:
  assert_true_rule_blob(
      "import \"dex\" rule test { condition: dex.field[0].name == \
        \"applicationId\" }",
      DEX_FILE);
          break;
      case 118:
  assert_true_rule_blob(
      "import \"dex\" rule test { condition: dex.number_of_methods == 2 }",
      DEX_FILE);
          break;
      case 119:
  assert_true_rule_blob(
      "import \"dex\" rule test { condition: dex.method[0].class_name == \
        \"Lcom/android/tools/ir/server/AppInfo;\" }",
      DEX_FILE);
          break;
      case 120:
  assert_true_rule_blob(
      "import \"dex\" rule test { condition: dex.method[0].proto == \"V\" }",
      DEX_FILE);
          break;
      case 121:
  assert_true_rule_blob(
      "import \"dex\" rule test { condition: dex.method[0].name == \
        \"<clinit>\" }",
      DEX_FILE);
          break;
      case 122:
  assert_true_rule_blob(
      "import \"dex\" rule test { condition: dex.method[1].name == \
        \"<init>\" }",
      DEX_FILE);
          break;
      case 123:
  assert_true_rule_blob(
      "import \"dex\" rule test { condition: dex.map_list.size == 12 }",
      DEX_FILE);
          break;
      case 124:
  assert_true_rule_blob(
      "import \"dex\" rule test { condition: \
          dex.map_list.map_item[0].type == dex.TYPE_HEADER_ITEM \
        }",
      DEX_FILE);
          break;
  }

  yr_finalize();
}
