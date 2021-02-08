cmake_minimum_required(VERSION 3.1)
project(test_bsvv C)

file (GLOB TESTBSV_SOURCE  "*.c")
source_group("bsv_test_source" FILES ${TESTBSV_SOURCE})

# And add the main as an executable ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
enable_testing()
add_executable(test_bsvv ${TESTBSV_SOURCE})    
find_path(SIMDE_INCLUDE_DIRS "simde")
target_include_directories(test_bsvv PRIVATE ${SIMDE_INCLUDE_DIRS})
target_include_directories(test_bsvv PRIVATE "../include/")
find_package(check CONFIG REQUIRED)
target_link_libraries(test_bsvv PRIVATE Check::check)
target_compile_definitions(test_bsvv PUBLIC _CRT_SECURE_NO_WARNINGS)


