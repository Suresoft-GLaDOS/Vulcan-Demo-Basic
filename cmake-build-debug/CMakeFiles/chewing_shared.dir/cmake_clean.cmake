file(REMOVE_RECURSE
  "libchewing.pdb"
  "libchewing.so"
  "libchewing.so.3"
  "libchewing.so.3.1.0"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/chewing_shared.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
