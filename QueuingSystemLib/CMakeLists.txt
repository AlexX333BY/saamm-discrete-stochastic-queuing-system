set(HEADERS
        tickable.h
        job.h
        queuing_node_base.h
        queuing_receiver_base.h
        jobs_queue.h
        jobs_server_base.h
        final_jobs_server.h
        jobs_producer_base.h
        fixed_time_jobs_producer_base.h
        bouncing_jobs_producer_base.h
        fixed_time_bouncing_jobs_producer.h
)

set(SOURCES
        tickable.cpp
        job.cpp
        queuing_node_base.cpp
        queuing_receiver_base.cpp
        jobs_queue.cpp
        jobs_server_base.cpp
        final_jobs_server.cpp
        jobs_producer_base.cpp
        fixed_time_jobs_producer_base.cpp
        bouncing_jobs_producer_base.cpp
        fixed_time_bouncing_jobs_producer.cpp
)

add_library(QueuingSystemLib ${HEADERS} ${SOURCES})
set_target_properties(QueuingSystemLib PROPERTIES OUTPUT_NAME "libqueuingsystem")
