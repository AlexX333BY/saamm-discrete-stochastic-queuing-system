#include "queuing_node_base.h"
#include "queuing_receiver_base.h"

using namespace queuing_system;

queuing_node_base::queuing_node_base() : connected_nodes()
{ }

void queuing_node_base::connect_next(const std::shared_ptr<queuing_receiver_base>& next_node)
{
    if (next_node) {
        connected_nodes.push_back(next_node);
    }
}

std::vector<std::shared_ptr<queuing_receiver_base>>& queuing_node_base::get_connected_nodes()
{
    return connected_nodes;
}

void queuing_node_base::tick()
{
    for (const std::shared_ptr<queuing_receiver_base>& node : get_connected_nodes()) {
        node->tick();
    }
    on_tick();
}
