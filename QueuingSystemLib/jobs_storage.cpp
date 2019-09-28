#include "jobs_storage.h"

using namespace queuing_system;

jobs_storage::jobs_storage() : jobs()
{ }

const std::vector<std::shared_ptr<job>>& jobs_storage::get_jobs() const
{
    return jobs;
}

void jobs_storage::store_job(const std::shared_ptr<job> &job)
{
    if (job) {
        jobs.push_back(job);
    }
}
