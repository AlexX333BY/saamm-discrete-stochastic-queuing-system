#ifndef DISCRETESTOCHASTICQUEUINGSYSTEM_JOBS_QUEUE_H
#define DISCRETESTOCHASTICQUEUINGSYSTEM_JOBS_QUEUE_H


#include "queuing_receiver_base.h"
#include "job.h"
#include <memory>
#include <queue>

namespace queuing_system {
    class jobs_queue : public queuing_receiver_base {
    public:
        explicit jobs_queue(const size_t size);

        size_t get_length() const;
        bool can_receive_job() final;

    protected:
        void on_job_received(const std::shared_ptr<job>& job) final;
        void on_tick() final;

    private:
        const size_t queue_size;
        std::deque<std::shared_ptr<job>> jobs;
    };
}


#endif //DISCRETESTOCHASTICQUEUINGSYSTEM_JOBS_QUEUE_H
