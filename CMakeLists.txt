cmake_minimum_required(VERSION 3.10)
project( BladeRFPiEventAnalyzer
        VERSION 0.1.1
        DESCRIPTION "RF Event Analyzer builded on base of BladeRF and RaspberryPI"
        LANGUAGES C CXX)
find_package(PkgConfig REQUIRED)
pkg_check_modules(BlRF REQUIRED IMPORTED_TARGET libbladeRF)
add_executable(BladerRFMain src/main.c)
target_link_libraries(BladerRFMain PRIVATE PkgConfig::BlRF)
