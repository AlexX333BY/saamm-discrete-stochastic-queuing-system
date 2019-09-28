#ifndef DISCRETESTOCHASTICQUEUINGSYSTEM_JOB_H
#define DISCRETESTOCHASTICQUEUINGSYSTEM_JOB_H


#include "tickable.h"

namespace queuing_system {
    class job : public tickable {
    public:
        enum class job_status {
            produced,
            bounced,
            queued,
            processing,
            done
        };

        job();

        void tick() final;

        int get_time_in_system() const;

        int get_time_in_queue() const;

        job_status get_status() const;

        void set_status(const job_status status);

    private:
        job_status status;
        int time_in_system;
        int time_in_queue;
    };
}


#endif //DISCRETESTOCHASTICQUEUINGSYSTEM_JOB_H
