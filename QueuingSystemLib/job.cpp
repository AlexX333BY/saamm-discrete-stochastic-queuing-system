#include "job.h"

using namespace queuing_system;

job::job() : status(job_status::produced), time_in_queue(0), time_in_system(0)
{ }

job::job_status job::get_status() const
{
    return status;
}

int job::get_time_in_queue() const
{
    return time_in_queue;
}

int job::get_time_in_system() const
{
    return time_in_system;
}

void job::set_status(const queuing_system::job::job_status new_status)
{
    status = new_status;
}

void job::tick()
{
    if ((status != job_status::done) && (status != job_status::bounced)) {
        ++time_in_system;
    }

    if (status == job_status::queued) {
        ++time_in_queue;
    }
}
