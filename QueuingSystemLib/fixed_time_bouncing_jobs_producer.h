#ifndef DISCRETESTOCHASTICQUEUINGSYSTEM_FIXED_TIME_BOUNCING_JOBS_PRODUCER_H
#define DISCRETESTOCHASTICQUEUINGSYSTEM_FIXED_TIME_BOUNCING_JOBS_PRODUCER_H


#include "bouncing_jobs_producer_base.h"
#include "fixed_time_jobs_producer_base.h"

namespace queuing_system {
    class fixed_time_bouncing_jobs_producer : public fixed_time_jobs_producer_base, public bouncing_jobs_producer_base {
    public:
        explicit fixed_time_bouncing_jobs_producer(const int ticks_per_generation);
    };
}


#endif //DISCRETESTOCHASTICQUEUINGSYSTEM_FIXED_TIME_BOUNCING_JOBS_PRODUCER_H
