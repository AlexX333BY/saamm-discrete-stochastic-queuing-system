#include "model_parameters_parser.h"
#include <iostream>
#include "fixed_time_bouncing_jobs_producer.h"
#include "jobs_queue.h"
#include "final_jobs_server.h"

struct modelling_params
{
    unsigned int total_ticks;
    unsigned int ticks_per_job;
    size_t queue_size;
    double first_screening_probability;
    double second_screening_probability;
};

struct modelling_results
{
    double deviation_probability;
    double absolute_throughput;
    double average_time_in_queue;
};

modelling_results model(const modelling_params& params)
{
    auto producer = std::make_shared<queuing_system::fixed_time_bouncing_jobs_producer>(params.ticks_per_job);
    auto queue = std::make_shared<queuing_system::jobs_queue>(params.queue_size);
    auto first_server = std::make_shared<queuing_system::final_jobs_server>(params.first_screening_probability),
            second_server = std::make_shared<queuing_system::final_jobs_server>(params.second_screening_probability);

    producer->connect_next(queue);
    queue->connect_next(first_server);
    queue->connect_next(second_server);
    for (unsigned int i = 0; i < params.total_ticks; ++i) {
        producer->tick();
    }

    unsigned int bounced_jobs_count = 0,
        served_jobs_count = 0,
        non_bounced_jobs_count = 0;
    double sum_of_relative_time_in_queue = 0;
    for (const std::shared_ptr<queuing_system::job>& job : producer->get_produced_jobs()) {
        if (job->get_status() == queuing_system::job::job_status::bounced) {
            ++bounced_jobs_count;
        } else {
            ++non_bounced_jobs_count;
        }

        if (job->get_time_in_system() != 0) {
            sum_of_relative_time_in_queue += (double)job->get_time_in_queue() / job->get_time_in_system();
        }

        if (job->get_status() == queuing_system::job::job_status::done) {
            ++served_jobs_count;
        }
    }

    modelling_results result;
    result.deviation_probability = (double)bounced_jobs_count / (served_jobs_count + bounced_jobs_count);
    result.absolute_throughput = (double)served_jobs_count / params.total_ticks;
    result.average_time_in_queue = sum_of_relative_time_in_queue / non_bounced_jobs_count;
    return result;
}

int main(int argc, char** argv)
{
    model_parameters_parser parser(argc, argv);
    model_parameters_parser::parse_result parse_result = parser.parse();

    modelling_params params;
    modelling_results results;
    switch (parser.parse()) {
        case model_parameters_parser::parse_result::ok:
            params.total_ticks = parser.get_total_ticks_count();
            params.second_screening_probability = parser.get_second_screening_probability();
            params.first_screening_probability = parser.get_first_screening_probability();
            params.queue_size = parser.get_queue_size();
            params.ticks_per_job = parser.get_ticks_count_per_job_generation();
            results = model(params);

            std::cout << "Pdev = " << results.deviation_probability << std::endl
                << "A = " << results.absolute_throughput << std::endl
                << "Wq = " << results.average_time_in_queue << std::endl;
            break;
        case model_parameters_parser::parse_result::wrong_arguments:
        case model_parameters_parser::parse_result::help:
            std::cout << parser.get_help_message() << std::endl;
            break;
    }

    return 0;
}
