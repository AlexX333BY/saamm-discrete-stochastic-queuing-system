set(HEADERS
        tickable.h
        job.h
        jobs_storage.h
        queuing_node_base.h
        queuing_receiver_base.h
)

set(SOURCES
        tickable.cpp
        job.cpp
        jobs_storage.cpp
        queuing_node_base.cpp
        queuing_receiver_base.cpp
)

add_library(QueuingSystemLib ${HEADERS} ${SOURCES})
set_target_properties(QueuingSystemLib PROPERTIES OUTPUT_NAME "libqueuingsystem")
