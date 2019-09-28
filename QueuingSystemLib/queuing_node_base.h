#ifndef DISCRETESTOCHASTICQUEUINGSYSTEM_QUEUING_NODE_BASE_H
#define DISCRETESTOCHASTICQUEUINGSYSTEM_QUEUING_NODE_BASE_H


#include <memory>
#include <vector>
#include "tickable.h"

namespace queuing_system {
    class queuing_receiver_base;

    class queuing_node_base : public tickable {
    public:
        queuing_node_base();

        void connect_next(const std::shared_ptr<queuing_receiver_base>& next_node);
        void tick() final;

    protected:
        virtual void on_tick() = 0;
        std::vector<std::shared_ptr<queuing_receiver_base>>& get_connected_nodes();

    private:
        std::vector<std::shared_ptr<queuing_receiver_base>> connected_nodes;
    };
}


#endif //DISCRETESTOCHASTICQUEUINGSYSTEM_QUEUING_NODE_BASE_H
