cmake_minimum_required(VERSION 3.17)


project(Game VERSION 0.1)

find_package(raylib 5.5.0 REQUIRED)

#set(CMAKE_CPP_STANDARD 11)
set(CMAKE_CPP_STANDARD 23)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable( ${PROJECT_NAME} ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

#add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} raylib)
