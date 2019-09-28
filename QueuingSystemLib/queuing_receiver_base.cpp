#include "queuing_receiver_base.h"

using namespace queuing_system;

queuing_receiver_base::queuing_receiver_base(const job::job_status status_on_receive)
    : queuing_node_base(), job_status_on_receive(status_on_receive)
{ }

void queuing_receiver_base::receive_job(const std::shared_ptr<job>& job)
{
    if (job && can_receive_job()) {
        on_job_received(job);
    }
}
