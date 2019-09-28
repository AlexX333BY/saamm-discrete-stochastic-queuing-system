#ifndef DISCRETESTOCHASTICQUEUINGSYSTEM_BOUNCING_JOBS_PRODUCER_BASE_H
#define DISCRETESTOCHASTICQUEUINGSYSTEM_BOUNCING_JOBS_PRODUCER_BASE_H


#include "jobs_producer_base.h"

namespace queuing_system {
    class bouncing_jobs_producer_base : virtual public jobs_producer_base {
    public:
        bouncing_jobs_producer_base();

    protected:
        void on_tick() final;
    };
}


#endif //DISCRETESTOCHASTICQUEUINGSYSTEM_BOUNCING_JOBS_PRODUCER_BASE_H
