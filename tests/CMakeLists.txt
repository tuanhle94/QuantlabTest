cmake_minimum_required(VERSION 3.19)

add_executable(QuantlabTests "FooTests.cpp" "CSVParserTests.cpp" "CalculatorTests.cpp")
target_link_libraries(QuantlabTests Quantlab gtest gtest_main)

get_target_property(QUANTLAB_BINARY_DIR Quantlab BINARY_DIR)
message("The working directory: ${QUANTLAB_BINARY_DIR}")

gtest_discover_tests(QuantlabTests 
                     WORKING_DIRECTORY ${QUANTLAB_BINARY_DIR})

#Copy input file
configure_file(sample_files/input.csv ${QUANTLAB_BINARY_DIR}/sample_files/input.csv COPYONLY)
configure_file(sample_files/small_input.csv ${QUANTLAB_BINARY_DIR}/sample_files/small_input.csv COPYONLY)

