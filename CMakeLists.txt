cmake_minimum_required(VERSION 3.19)

project(Quantlab)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Import the GenerateExportHeader module and set the default symbol visibility to hidden.
# GenerateExportHeader documentation: https://cmake.org/cmake/help/latest/module/GenerateExportHeader.html
# Export header files created with generate_export_header will need to be included with the 
# rest of the public headers. 

include(GenerateExportHeader)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)


add_subdirectory(src)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)

    if (BUILD_TESTING)
        include(GoogleTest)
        add_subdirectory(${PROJECT_SOURCE_DIR}/extern EXCLUDE_FROM_ALL)
        add_subdirectory(tests)
    endif()
endif()