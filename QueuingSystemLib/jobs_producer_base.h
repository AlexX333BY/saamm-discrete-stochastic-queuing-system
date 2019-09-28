#ifndef DISCRETESTOCHASTICQUEUINGSYSTEM_JOBS_PRODUCER_BASE_H
#define DISCRETESTOCHASTICQUEUINGSYSTEM_JOBS_PRODUCER_BASE_H


#include "queuing_node_base.h"
#include "job.h"
#include <memory>
#include <vector>

namespace queuing_system {
    class jobs_producer_base : public queuing_node_base {
    public:
        jobs_producer_base();

        const std::vector<std::shared_ptr<job>>& get_produced_jobs() const;

    protected:
        void add_produced_job(const std::shared_ptr<job>& job);
        virtual std::shared_ptr<job> try_produce() = 0;

    private:
        std::vector<std::shared_ptr<job>> produced_jobs;
    };
}


#endif //DISCRETESTOCHASTICQUEUINGSYSTEM_JOBS_PRODUCER_BASE_H
