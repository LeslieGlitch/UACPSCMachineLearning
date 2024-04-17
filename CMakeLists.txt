# @file CMakeLists.txt
# 
# CMake files for Machine Learning Project

cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(MachineLearning)

# MachineLearning
add_executable(MachineLearning)
target_sources(MachineLearning PRIVATE main.cpp LinearList.cpp Backpropagation.cpp)
target_compile_features(MachineLearning PRIVATE cxx_std_17)
target_compile_options(MachineLearning PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/Wall>
    $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:-Wall>
)

# run
add_custom_target(run
        COMMENT "Run"
        COMMAND $<TARGET_FILE:MachineLearning>
        DEPENDS MachineLearning
        USES_TERMINAL
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
