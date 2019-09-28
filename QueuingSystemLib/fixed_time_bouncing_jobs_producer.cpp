#include "fixed_time_bouncing_jobs_producer.h"

using namespace queuing_system;

fixed_time_bouncing_jobs_producer::fixed_time_bouncing_jobs_producer(const int ticks_per_generation)
    : fixed_time_jobs_producer_base(ticks_per_generation), bouncing_jobs_producer_base()
{}
