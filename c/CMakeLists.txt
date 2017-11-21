add_library(lispcaft SHARED lispcraft.h gl.c windowlib.c)

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-O2")        ## Optimize
endif()
