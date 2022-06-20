cmake_minimum_required(VERSION 3.19)

add_library(Quantlab SHARED Foo.cpp  "CSVParser.cpp" "Calculator.cpp")

target_include_directories(Quantlab PUBLIC "${PROJECT_SOURCE_DIR}/include" "${CMAKE_CURRENT_BINARY_DIR}")

generate_export_header(Quantlab EXPORT_FILE_NAME Quantlab/QuantlabExports.h)