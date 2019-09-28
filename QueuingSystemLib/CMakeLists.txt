set(HEADERS
    tickable.h
    job.h
    jobs_storage.h
)

set(SOURCES
    tickable.cpp
    job.cpp
    jobs_storage.cpp
)

add_library(QueuingSystemLib ${HEADERS} ${SOURCES})
set_target_properties(QueuingSystemLib PROPERTIES OUTPUT_NAME "libqueuingsystem")
