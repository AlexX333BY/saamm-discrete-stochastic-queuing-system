#ifndef DISCRETESTOCHASTICQUEUINGSYSTEM_TICKABLE_H
#define DISCRETESTOCHASTICQUEUINGSYSTEM_TICKABLE_H


namespace queuing_system {
    class tickable {
    public:
        virtual ~tickable();

        virtual void tick() = 0;
    };
}


#endif //DISCRETESTOCHASTICQUEUINGSYSTEM_TICKABLE_H
