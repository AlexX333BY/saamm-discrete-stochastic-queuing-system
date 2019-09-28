set(HEADERS
    tickable.h
)

set(SOURCE
    tickable.cpp
)

add_library(QueuingSystemLib ${HEADERS} ${SOURCES})
set_target_properties(QueuingSystemLib PROPERTIES OUTPUT_NAME "libqueuingsystem")
