cmake_minimum_required (VERSION 3.1)

set (CMAKE_C_FLAGS "")
set (CMAKE_SYSTEM_NAME Linux)
enable_language(ASM)
project(main)

MACRO(ADD_INC)
  set(_args ${ARGN})
  foreach(dir ${_args})
    # message("dir= " ${dir})
    include_directories(${dir})
  endforeach(dir)
ENDMACRO(ADD_INC)

MACRO(ADD_SRC VAR)
  set(_args ${ARGN})
  # message("macro add_src var=" ${VAR} " args= " ${_args})
  foreach(dir ${_args})
    # message("dir= " ${dir})
    aux_source_directory(${dir} ${VAR})
  endforeach(dir)
ENDMACRO(ADD_SRC)

set(ROOT_DIR ${PROJECT_BINARY_DIR}/../)
set(CMAKE_BINARY_DIR ${PROJECT_BINARY_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

# log
ADD_INC(${ROOT_DIR} ../lib/log)
aux_source_directory (${ROOT_DIR}/lib/log SRCS)

# misc
ADD_INC(${ROOT_DIR} ../lib/misc)
aux_source_directory (${ROOT_DIR}/lib/misc SRCS)

# sort
ADD_INC(${ROOT_DIR} ../sort/bubble/)
aux_source_directory (${ROOT_DIR}/sort/bubble/ SRCS)

# tree
ADD_INC(${ROOT_DIR} ../tree/)
aux_source_directory (${ROOT_DIR}/tree/ SRCS)

# app
aux_source_directory (${ROOT_DIR}/app/ SRCS)

add_executable (main  ${SRCS})
