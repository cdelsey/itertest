cmake_minimum_required (VERSION 2.8)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

SET(CMAKE_CXX_FLAGS "-std=c++11 -Wall ${CMAKE_CXX_FLAGS}")

if(${CMAKE_EXTRA_GENERATOR} MATCHES "Eclipse CDT4")
    set(CMAKE_CXX_COMPILER_ARG1 "-std=c++11" CACHE STRING "C++ version for eclipse" FORCE)
    #set(CMAKE_ECLIPSE_VERSION "4.4" CACHE STRING "Eclipse version" FORCE)
endif()

function( create_test TESTNAME ADDITIONAL_FILES ADDITIONAL_LIBRARIES )
    add_executable( ${TESTNAME}
        ${TESTNAME}.cpp
        ${ADDITIONAL_FILES} )

    target_link_libraries( ${TESTNAME}
        gtest
        gtest_main
        ${ADDITIONAL_LIBRARIES} )

    add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
endfunction()

project (itertest)
enable_testing()

add_subdirectory(src)
add_subdirectory(lib)
