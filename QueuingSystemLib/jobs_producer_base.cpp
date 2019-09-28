#include "jobs_producer_base.h"

using namespace queuing_system;

jobs_producer_base::jobs_producer_base() : produced_jobs()
{ }

const std::vector<std::shared_ptr<job>>& jobs_producer_base::get_produced_jobs() const
{
    return produced_jobs;
}

void jobs_producer_base::add_produced_job(const std::shared_ptr<job>& job)
{
    if (job) {
        produced_jobs.push_back(job);
    }
}
