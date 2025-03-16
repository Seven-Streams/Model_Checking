# filepath: /home/yuchuan/Model_Checking/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(ModelChecker)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/grammar)
include_directories(/usr/local/include/antlr4-runtime)
link_directories(/usr/local/lib)

file(GLOB SOURCES "grammar/*.cpp")

add_executable(ModelChecker 
main.cpp
Transform/Simplify.cpp
Transform/BuildElementarySet.cpp
Transform/BuildNBA.cpp
Translate/TSParser.cpp
CheckOnProduct/Product.cpp
${SOURCES})
target_link_libraries(ModelChecker antlr4-runtime)