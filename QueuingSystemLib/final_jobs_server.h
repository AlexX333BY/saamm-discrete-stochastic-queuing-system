#ifndef DISCRETESTOCHASTICQUEUINGSYSTEM_FINAL_JOBS_SERVER_H
#define DISCRETESTOCHASTICQUEUINGSYSTEM_FINAL_JOBS_SERVER_H


#include "jobs_server_base.h"

namespace queuing_system {
    class final_jobs_server : public jobs_server_base {
    public:
        explicit final_jobs_server(const double screening_probability);

    protected:
        void on_tick() final;
    };
}


#endif //DISCRETESTOCHASTICQUEUINGSYSTEM_FINAL_JOBS_SERVER_H
