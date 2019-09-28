#ifndef DISCRETESTOCHASTICQUEUINGSYSTEM_JOBS_STORAGE_H
#define DISCRETESTOCHASTICQUEUINGSYSTEM_JOBS_STORAGE_H


#include <memory>
#include <vector>
#include "job.h"

namespace queuing_system {
    class jobs_storage {
    public:
        jobs_storage();

        void store_job(const std::shared_ptr<job> &job);

        const std::vector<std::shared_ptr<job>> &get_jobs() const;

    private:
        std::vector<std::shared_ptr<job>> jobs;
    };
}


#endif //DISCRETESTOCHASTICQUEUINGSYSTEM_JOBS_STORAGE_H
