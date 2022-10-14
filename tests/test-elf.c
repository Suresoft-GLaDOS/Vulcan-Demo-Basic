#include <yara.h>
#include "util.h"
#include "blob.h"
#include "defects4cpp.h"

int main(int argc, char** argv)
{
  yr_initialize();
  int index = defects4cpp_test_index();
  switch (index) {
      case 125:
  assert_true_rule_blob(
      "import \"elf\" rule test { condition: elf.type }",
      ELF32_FILE);
          break;
      case 126:
  assert_true_rule_blob(
      "import \"elf\" rule test { condition: elf.type }",
      ELF64_FILE);
          break;
      case 127:
  assert_true_rule_blob(
      "import \"elf\" rule test { condition: elf.machine == elf.EM_386 }",
      ELF32_FILE)
          break;
      case 128:
  assert_true_rule_blob(
      "import \"elf\" rule test { condition: elf.machine == elf.EM_X86_64 }",
      ELF64_FILE)
          break;
      case 129:
  assert_true_rule_blob(
      "import \"elf\" \
      rule test { \
        strings: $a = { b8 01 00 00 00 bb 2a } \
        condition: $a at elf.entry_point \
      }",
      ELF32_FILE);
          break;
      case 130:
  assert_true_rule_blob(
      "import \"elf\" \
      rule test { \
        strings: $a = { b8 01 00 00 00 bb 2a } \
        condition: $a at elf.entry_point \
      }",
      ELF64_FILE);
          break;
      case 131:
  assert_true_rule_blob(
      "import \"elf\" rule test { condition: elf.entry_point == 0xa0 }",
      ELF32_NOSECTIONS);
          break;
      case 132:
  assert_true_rule_blob(
      "import \"elf\" rule test { condition: elf.entry_point == 0x1a0 }",
      ELF32_SHAREDOBJ);
        break;
      case 133:
  assert_true_rule_blob(
      "import \"elf\" \
      rule test { \
        condition: elf.sections[2].name == \".comment\" \
      }",
      ELF64_FILE);
          break;
      case 134:
  assert_true_rule_blob(
      "import \"elf\" \
      rule test { \
        condition: elf.machine == elf.EM_MIPS \
      }",
      ELF32_MIPS_FILE);
          break;
      case 135:
  assert_true_rule_blob(
      "import \"elf\" \
      rule test { \
        condition: \
          elf.number_of_sections == 35 and elf.number_of_segments == 10 \
      }",
      ELF32_MIPS_FILE);
          break;
      case 136:
  assert_true_rule_blob(
      "import \"elf\" \
      rule test { \
        condition: \
          for any i in (0..elf.number_of_sections): ( \
            elf.sections[i].type == elf.SHT_PROGBITS and  \
            elf.sections[i].address == 0x400600 and \
            elf.sections[i].name == \".text\") \
      }",
      ELF32_MIPS_FILE);
          break;
      case 137:
  assert_true_rule_blob(
      "import \"elf\" \
        rule test { \
          condition: \
            for any i in (0..elf.number_of_segments): ( \
            elf.segments[i].type == elf.PT_LOAD and \
            elf.segments[i].virtual_address == 0x00400000 and \
            elf.segments[i].file_size == 0x95c)\
      }",
      ELF32_MIPS_FILE);
          break;
      case 138:
  assert_true_rule_blob(
      "import \"elf\" \
      rule test { \
        condition: \
          elf.dynamic_section_entries == 19 and \
          elf.symtab_entries == 80 \
      }",
      ELF32_MIPS_FILE);
          break;
      case 139:
  assert_true_rule_blob(
      "import \"elf\" \
      rule test { \
        condition: \
          for any i in (0..elf.symtab_entries): ( \
            elf.symtab[i].shndx == 9 and \
            elf.symtab[i].value == 0x400650 and \
            elf.symtab[i].name == \"_start_c\") \
      }",
      ELF32_MIPS_FILE);
          break;
      case 140:
  assert_true_rule_blob(
      "import \"elf\" \
      rule test { \
        condition: \
          elf.symtab[68].name == \"_start_c\" and \
          elf.symtab[68].type == elf.STT_FUNC and \
          elf.symtab[68].bind == elf.STB_GLOBAL and \
          elf.symtab[68].value == 0x400650 and \
          elf.symtab[68].size == 56 \
      }",
      ELF32_MIPS_FILE);
          break;
      case 141:
  assert_true_rule_blob(
      "import \"elf\" \
      rule test { \
        condition: \
          elf.dynamic[4].type == elf.DT_STRTAB and \
          elf.dynamic[4].val == 0x400484\
      }",
      ELF32_MIPS_FILE);
          break;
      case 142:
  assert_true_rule_blob(
      "import \"elf\" \
      rule test { \
        condition: \
          for any i in (0..elf.dynamic_section_entries): ( \
            elf.dynamic[i].type == 0x70000006 and \
            elf.dynamic[i].val == 0x400000)\
      }",
      ELF32_MIPS_FILE);
          break;
      case 143:
  assert_true_rule_blob(
      "import \"elf\" \
      rule test { \
        condition: elf.machine == elf.EM_X86_64 \
      }",
      ELF_x64_FILE);
          break;
      case 144:
  assert_true_rule_blob(
      "import \"elf\" \
      rule test { \
        condition: \
          elf.number_of_sections == 22 and \
          elf.number_of_segments == 7 \
      }",
      ELF_x64_FILE);
          break;
      case 145:
  assert_true_rule_blob(
      "import \"elf\" \
      rule test { \
        condition: \
          for any i in (0..elf.number_of_sections): ( \
            elf.sections[i].type == elf.SHT_PROGBITS and \
            elf.sections[i].address == 0x601000 and \
            elf.sections[i].name == \".got.plt\") \
      }",
      ELF_x64_FILE);
          break;
      case 146:
  assert_true_rule_blob(
      "import \"elf\" \
      rule test { \
         condition: \
            for any i in (0..elf.number_of_segments): ( \
              elf.segments[i].type == elf.PT_LOAD and \
              elf.segments[i].virtual_address == 0x600e78 and \
              elf.segments[i].file_size == 0x1b0) \
      }",
      ELF_x64_FILE);
          break;
      case 147:
  assert_true_rule_blob(
      "import \"elf\" \
      rule test { \
         condition: \
            elf.dynamic_section_entries == 18 and \
            elf.symtab_entries == 48  \
      }",
      ELF_x64_FILE);
          break;
      case 148:
  assert_true_rule_blob(
      "import \"elf\" \
      rule test { \
        condition: \
          for any i in (0..elf.symtab_entries): ( \
            elf.symtab[i].shndx == 8 and \
            elf.symtab[i].value == 0x400400 and \
            elf.symtab[i].name == \"main\") \
     }",
     ELF_x64_FILE);
          break;
      case 149:
  assert_true_rule_blob(
      "import \"elf\" \
      rule test { \
        condition: \
          elf.symtab[20].name == \"__JCR_LIST__\" and \
          elf.symtab[20].type == elf.STT_OBJECT and \
          elf.symtab[20].bind == elf.STB_LOCAL and \
          elf.symtab[20].value == 0x600e88 and \
          elf.symtab[20].size == 0 \
      }",
      ELF_x64_FILE);
          break;
      case 150:
  assert_true_rule_blob(
      "import \"elf\" \
      rule test { \
        condition: \
          elf.dynamic[13].type == elf.DT_PLTGOT and \
          elf.dynamic[13].val == 0x601000 \
     }",
     ELF_x64_FILE);
          break;
      case 151:
  assert_true_rule_blob(
      "import \"elf\" \
      rule test { \
        condition: \
          for any i in (0..elf.dynamic_section_entries): ( \
            elf.dynamic[i].type == elf.DT_JMPREL and \
            elf.dynamic[i].val == 0x4003c0) \
      }",
      ELF_x64_FILE);
          break;
  }
  yr_finalize();
}
