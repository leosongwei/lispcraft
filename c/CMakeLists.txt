cmake_minimum_required (VERSION 3.9)
project(lispcaftc VERSION 0.0.1 DESCRIPTION "liblispcaftc")
add_library(lispcaftc SHARED ./cpart.c)

set_target_properties(lispcaftc PROPERTIES
    VERSION 0.0.1
    PUBLIC_HEADER cpart.h)
