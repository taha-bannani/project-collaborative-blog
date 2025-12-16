# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\projet_cb_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\projet_cb_autogen.dir\\ParseCache.txt"
  "projet_cb_autogen"
  )
endif()
