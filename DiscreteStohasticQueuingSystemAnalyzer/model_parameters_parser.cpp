#include "model_parameters_parser.h"
#include <sstream>

const std::string model_parameters_parser::TOTAL_TICKS_COUNT_ARGUMENT("total-ticks"),
    model_parameters_parser::TICKS_COUNT_PER_JOB_GEN_ARGUMENT("ticks-per-job-gen"),
    model_parameters_parser::QUEUE_SIZE_ARGUMENT("queue-length"),
    model_parameters_parser::FIRST_SCREENING_PROBABILITY_ARGUMENT("p1"),
    model_parameters_parser::SECOND_SCREENING_PROBABILITY_ARGUMENT("p2"),
    model_parameters_parser::HELP_ARGUMENT("help");

model_parameters_parser::model_parameters_parser(int argc, char **argv)
    : args_count(argc),
    args(argv),
    total_ticks_count(0),
    ticks_count_per_job_generation(0),
    queue_size(0),
    p1(0),
    p2(0),
    desc("Discrete-stohastic queuing system model")
{
    desc.add_options()
        (
            HELP_ARGUMENT.c_str(),
            "Print help")
        (
            TOTAL_TICKS_COUNT_ARGUMENT.c_str(),
            boost::program_options::value<unsigned int>(&total_ticks_count),
            "System ticks count"
        )
        (
            TICKS_COUNT_PER_JOB_GEN_ARGUMENT.c_str(),
            boost::program_options::value<unsigned int>(&ticks_count_per_job_generation)->default_value(2),
            "Ticks for single job generation")
        (
            QUEUE_SIZE_ARGUMENT.c_str(),
            boost::program_options::value<size_t>(&queue_size)->default_value(1),
            "Queue size"
        )
        (
            FIRST_SCREENING_PROBABILITY_ARGUMENT.c_str(),
            boost::program_options::value<double>(&p1)->default_value(0.8),
            "p1"
        )
        (
            SECOND_SCREENING_PROBABILITY_ARGUMENT.c_str(),
            boost::program_options::value<double>(&p2)->default_value(0.6),
            "p2"
        );
}

model_parameters_parser::parse_result model_parameters_parser::parse()
{
    parse_result result = parse_result::wrong_arguments;
    try {
        boost::program_options::store(boost::program_options::parse_command_line(args_count, args, desc), parser);
        boost::program_options::notify(parser);

        const bool has_help = this->has_help(),
            has_total_ticks = this->has_total_ticks_count();

        if (has_help && !has_total_ticks) {
            result = parse_result::help;
        }

        if (has_total_ticks && !has_help) {
            result = parse_result::ok;
        }
    } catch (const std::exception &) {
        result = parse_result::wrong_arguments;
    }

    return result;
}

bool model_parameters_parser::has_help() const
{
    return parser.count(HELP_ARGUMENT) > 0;
}

bool model_parameters_parser::has_total_ticks_count() const
{
    return parser.count(TOTAL_TICKS_COUNT_ARGUMENT) > 0;
}

double model_parameters_parser::get_first_screening_probability() const
{
    return p1;
}

double model_parameters_parser::get_second_screening_probability() const
{
    return p2;
}

size_t model_parameters_parser::get_queue_size() const
{
    return queue_size;
}

unsigned int model_parameters_parser::get_ticks_count_per_job_generation() const
{
    return ticks_count_per_job_generation;
}

unsigned int model_parameters_parser::get_total_ticks_count() const
{
    return total_ticks_count;
}

std::string model_parameters_parser::get_help_message() const
{
    std::ostringstream msg_stream;
    desc.print(msg_stream);
    return msg_stream.str();
}
