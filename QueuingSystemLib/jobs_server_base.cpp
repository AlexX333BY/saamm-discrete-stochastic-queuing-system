#include "jobs_server_base.h"
#include <random>

using namespace queuing_system;

jobs_server_base::jobs_server_base(const double probability) : queuing_receiver_base(job::job_status::processing),
    screening_probability(probability), serving_job()
{ }

bool jobs_server_base::is_occupied() const
{
    return (bool)serving_job;
}

bool jobs_server_base::can_receive_job()
{
    return !is_occupied();
}

bool jobs_server_base::try_serve_job() const
{
    std::random_device device;
    std::default_random_engine random_generator(device());
    return std::uniform_real_distribution<double>(0, 1)(random_generator) > screening_probability;
}

void jobs_server_base::on_job_received(const std::shared_ptr<job>& job)
{
    serving_job = job;
}

std::shared_ptr<job>& jobs_server_base::get_job()
{
    return serving_job;
}
