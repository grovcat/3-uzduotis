cmake_minimum_required (VERSION 3.0)
project ( 3_Uzduotis )

include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

add_executable( 3_Uzduotis main.cpp funkcijos.cpp StudentFunkcijos.cpp funk.h HumanClass.h StudentClass.h)