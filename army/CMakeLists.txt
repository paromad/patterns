set(SOURCES squad.h army.h)

add_library(army STATIC ${SOURCES})

target_link_libraries(army units)
target_link_libraries(army structure)