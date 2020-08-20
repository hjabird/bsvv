cmake_minimum_required(VERSION 3.1)
project(bsvv C)

set(BSVV_MAJOR 0)
set(BSVV_MINOR 1)
set(BSVV_PATCHLEVEL 0)
set(BSVV_VERSION ${BSVV_MAJOR}.${BSVV_MINOR}.${BSVV_PATCHLEVEL})

add_library(bsvv INTERFACE)
target_include_directories(bsvv
    INTERFACE 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

if (${CMAKE_C_COMPILER_ID} STREQUAL "GNU")
    link_libraries(bsvv m)   # Maths std library.
endif()

find_package(bsv CONFIG REQUIRED)
target_link_libraries(bsvv PUBLIC bsv)
target_include_directories(cvortex PUBLIC bsv)
find_package(SIMDE CONFIG REQUIRED)
target_link_libraries(bsvv PUBLIC bsv)
target_include_directories(bsvv PUBLIC bsv)

include(GNUInstallDirs)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(TARGETS bsvv
    EXPORT bsvv-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
install(EXPORT bsvv-targets
  FILE
    bsvv-config.cmake
  DESTINATION
    ${CMAKE_INSTALL_LIBDIR}/cmake/bsvv
)
