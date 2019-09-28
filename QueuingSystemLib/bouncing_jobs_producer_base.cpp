#include "bouncing_jobs_producer_base.h"
#include "job.h"
#include "queuing_receiver_base.h"

using namespace queuing_system;

bouncing_jobs_producer_base::bouncing_jobs_producer_base() : jobs_producer_base()
{ }

void bouncing_jobs_producer_base::on_tick()
{
    std::shared_ptr<job> produced_job = try_produce();

    if (produced_job) {
        add_produced_job(produced_job);

        for (std::shared_ptr<queuing_receiver_base>& node : get_connected_nodes()) {
            if (node->can_receive_job()) {
                node->receive_job(produced_job);
                produced_job.reset();
                break;
            }
        }

        if (produced_job) {
            produced_job->set_status(job::job_status::bounced);
        }
    }
}
