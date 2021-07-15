cmake_minimum_required(VERSION 3.19)

project(university_db)

set(CMAKE_CXX_STANDARD 14)
set(FILES Student.cpp Student.h)

add_library(lib STATIC ${FILES})
add_executable(${PROJECT_NAME} main.cpp ${FILES})
target_link_libraries(${PROJECT_NAME} lib)