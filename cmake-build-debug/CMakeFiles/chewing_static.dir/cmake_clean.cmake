file(REMOVE_RECURSE
  "libchewing.a"
  "libchewing.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/chewing_static.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
