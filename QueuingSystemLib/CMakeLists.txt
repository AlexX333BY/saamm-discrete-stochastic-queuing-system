set(HEADERS
    tickable.h
    job.h
)

set(SOURCES
    tickable.cpp
    job.cpp
)

add_library(QueuingSystemLib ${HEADERS} ${SOURCES})
set_target_properties(QueuingSystemLib PROPERTIES OUTPUT_NAME "libqueuingsystem")
