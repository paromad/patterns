cmake_minimum_required(VERSION 3.10)
project(Pat)

find_package(GTest REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/units)
include_directories(${PROJECT_SOURCE_DIR}/factories)
include_directories(${PROJECT_SOURCE_DIR}/structure)
include_directories(${PROJECT_SOURCE_DIR}/army)


add_subdirectory(${PROJECT_SOURCE_DIR}/units)
add_subdirectory(${PROJECT_SOURCE_DIR}/factories)
add_subdirectory(${PROJECT_SOURCE_DIR}/tests)
add_subdirectory(${PROJECT_SOURCE_DIR}/structure)
add_subdirectory(${PROJECT_SOURCE_DIR}/army)

add_executable(main main.cpp game.cpp)

target_link_libraries(main units)
target_link_libraries(main factories)
target_link_libraries(main structure)