#ifndef DISCRETESTOCHASTICQUEUINGSYSTEM_JOBS_SERVER_BASE_H
#define DISCRETESTOCHASTICQUEUINGSYSTEM_JOBS_SERVER_BASE_H


#include "queuing_receiver_base.h"

namespace queuing_system {
    class jobs_server_base : public queuing_receiver_base {
    public:
        explicit jobs_server_base(const double screening_probability);

        bool is_occupied() const;
        bool can_receive_job() final;

    protected:
        bool try_serve_job() const;
        void on_job_received(const std::shared_ptr<job>& job) final;
        std::shared_ptr<job>& get_job();

    private:
        const double screening_probability;
        std::shared_ptr<job> serving_job;
    };
}


#endif //DISCRETESTOCHASTICQUEUINGSYSTEM_JOBS_SERVER_BASE_H
