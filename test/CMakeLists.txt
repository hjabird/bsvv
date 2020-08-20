cmake_minimum_required(VERSION 3.1)

file (GLOB TESTBSV_SOURCE  "testmain.c")
source_group("bsv_test_source" FILES ${TESTBSV_SOURCE})


# And add the main as an executable ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
enable_testing()
add_executable(bsv_tests ${TESTBSV_SOURCE})
target_compile_definitions(bsv_tests PRIVATE _CRT_SECURE_NO_WARNINGS)


