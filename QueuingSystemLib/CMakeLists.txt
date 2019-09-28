set(HEADERS
        tickable.h
        job.h
        jobs_storage.h
        queuing_node_base.h
        queuing_receiver_base.h
        jobs_queue.h
        jobs_server_base.h
        final_jobs_server.h
)

set(SOURCES
        tickable.cpp
        job.cpp
        jobs_storage.cpp
        queuing_node_base.cpp
        queuing_receiver_base.cpp
        jobs_queue.cpp
        jobs_server_base.cpp
        final_jobs_server.cpp
)

add_library(QueuingSystemLib ${HEADERS} ${SOURCES})
set_target_properties(QueuingSystemLib PROPERTIES OUTPUT_NAME "libqueuingsystem")
