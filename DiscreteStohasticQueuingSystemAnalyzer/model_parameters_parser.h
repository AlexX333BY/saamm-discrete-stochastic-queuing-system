#ifndef DISCRETESTOCHASTICQUEUINGSYSTEM_PARSER_H
#define DISCRETESTOCHASTICQUEUINGSYSTEM_PARSER_H


#include <boost/program_options.hpp>
#include <string>

class model_parameters_parser {
public:
    enum class parse_result {
        ok,
        wrong_arguments,
        help
    };

    model_parameters_parser(int argc, char** argv);

    parse_result parse();

    bool has_total_ticks_count() const;
    bool has_help() const;
    unsigned int get_total_ticks_count() const;
    unsigned int get_ticks_count_per_job_generation() const;
    size_t get_queue_size() const;
    double get_first_screening_probability() const;
    double get_second_screening_probability() const;

private:
    boost::program_options::variables_map parser;
    const int args_count;
    char** args;
    unsigned int total_ticks_count, ticks_count_per_job_generation;
    size_t queue_size;
    double p1, p2;

    static const std::string TOTAL_TICKS_COUNT_ARGUMENT, TICKS_COUNT_PER_JOB_GEN_ARGUMENT, QUEUE_SIZE_ARGUMENT,
        FIRST_SCREENING_PROBABILITY_ARGUMENT, SECOND_SCREENING_PROBABILITY_ARGUMENT, HELP_ARGUMENT;
};


#endif //DISCRETESTOCHASTICQUEUINGSYSTEM_PARSER_H
