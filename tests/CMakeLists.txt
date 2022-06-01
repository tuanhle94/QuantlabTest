cmake_minimum_required(VERSION 3.19)


add_executable(QuantlabTests FooTest.cpp)
target_link_libraries(QuantlabTests Quantlab gtest gtest_main)

get_target_property(QUANTLAB_BINARY_DIR Quantlab BINARY_DIR)
message("The working directory: ${QUANTLAB_BINARY_DIR}")

gtest_discover_tests(QuantlabTests 
                     WORKING_DIRECTORY ${QUANTLAB_BINARY_DIR})