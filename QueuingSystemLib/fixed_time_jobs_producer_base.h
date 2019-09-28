#ifndef DISCRETESTOCHASTICQUEUINGSYSTEM_FIXED_TIME_JOBS_PRODUCER_BASE_H
#define DISCRETESTOCHASTICQUEUINGSYSTEM_FIXED_TIME_JOBS_PRODUCER_BASE_H


#include "jobs_producer_base.h"

namespace queuing_system {
    class fixed_time_jobs_producer_base : virtual public jobs_producer_base {
    public:
        explicit fixed_time_jobs_producer_base(const unsigned int ticks_per_generation);

    protected:
        std::shared_ptr<job> try_produce() final;

    private:
        const unsigned int ticks_per_generation;
        unsigned int ticks_left;
    };
}


#endif //DISCRETESTOCHASTICQUEUINGSYSTEM_FIXED_TIME_JOBS_PRODUCER_BASE_H
