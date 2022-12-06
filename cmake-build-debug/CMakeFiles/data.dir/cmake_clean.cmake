file(REMOVE_RECURSE
  "CMakeFiles/data"
  "chewing-definition.h"
  "data/ch_index_begin.dat"
  "data/ch_index_phone.dat"
  "data/dict.dat"
  "data/fonetree.dat"
  "data/ph_index.dat"
  "data/us_freq.dat"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/data.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
