set(SOURCES main_test.cpp tests.cpp)

add_executable(main_test ${SOURCES})

target_link_libraries(main_test ${GTEST_LIBRARIES} pthread)
target_link_libraries(main_test units)
target_link_libraries(main_test factories)
target_link_libraries(main_test structure)
target_link_libraries(main_test army)