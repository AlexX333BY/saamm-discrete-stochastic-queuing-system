#ifndef DISCRETESTOCHASTICQUEUINGSYSTEM_QUEUING_RECEIVER_BASE_H
#define DISCRETESTOCHASTICQUEUINGSYSTEM_QUEUING_RECEIVER_BASE_H


#include "queuing_node_base.h"
#include "job.h"

namespace queuing_system {
    class queuing_receiver_base : public queuing_node_base {
    public:
        explicit queuing_receiver_base(const job::job_status job_status_on_receive);

        void receive_job(const std::shared_ptr<job>& job);
        virtual bool can_receive_job() = 0;

    protected:
        virtual void on_job_received(const std::shared_ptr<job>& job) = 0;

    private:
        const job::job_status job_status_on_receive;
    };
}


#endif //DISCRETESTOCHASTICQUEUINGSYSTEM_QUEUING_RECEIVER_BASE_H
