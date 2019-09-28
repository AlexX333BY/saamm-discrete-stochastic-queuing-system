#include "fixed_time_jobs_producer_base.h"

using namespace queuing_system;

fixed_time_jobs_producer_base::fixed_time_jobs_producer_base(const int ticks) : jobs_producer_base(),
    ticks_per_generation(ticks), ticks_left(ticks)
{ }

std::shared_ptr<job> fixed_time_jobs_producer_base::try_produce()
{
    std::shared_ptr<job> produced_job;

    if (--ticks_left == 0) {
        produced_job = std::make_shared<job>();
        ticks_left = ticks_per_generation;
    }

    return produced_job;
}
