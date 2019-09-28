#include "final_jobs_server.h"

using namespace queuing_system;

final_jobs_server::final_jobs_server(const double screening_probability) : jobs_server_base(screening_probability)
{ }

void final_jobs_server::on_tick()
{
    std::shared_ptr<job>& serving_job = get_job();
    if (serving_job) {
        serving_job->tick();

        if (try_serve_job()) {
            serving_job->set_status(job::job_status::done);
            serving_job.reset();
        }
    }
}
