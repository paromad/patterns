set(SOURCES abstract_factory.h abstract_factory.cpp air_factory.h air_factory.cpp water_factory.h water_factory.cpp
        earth_factory.h earth_factory.cpp fire_factory.h fire_factory.cpp)

add_library(factories STATIC ${SOURCES})

target_link_libraries(factories units)