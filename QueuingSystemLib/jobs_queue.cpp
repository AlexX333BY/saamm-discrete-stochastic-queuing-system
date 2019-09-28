#include "jobs_queue.h"

using namespace queuing_system;

jobs_queue::jobs_queue(const size_t size) : queuing_receiver_base(job::job_status::queued),
    queue_size(size), jobs()
{ }

void jobs_queue::on_tick()
{
    for (std::shared_ptr<job>& job : jobs) {
        job->tick();
    }


    for (std::shared_ptr<queuing_receiver_base>& node : get_connected_nodes()) {
        if (jobs.empty()) {
            break;
        }

        if (node->can_receive_job()) {
            node->receive_job(jobs.front());
            jobs.pop_front();
        }
    }
}

void jobs_queue::on_job_received(const std::shared_ptr<job>& job)
{
    jobs.push_back(job);
}

bool jobs_queue::can_receive_job()
{
    return jobs.size() < queue_size;
}

size_t jobs_queue::get_length() const
{
    return queue_size;
}
