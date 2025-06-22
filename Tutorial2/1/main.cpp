#include "Agent.hpp"
#include "SuperAgent.hpp"

int main() {
    SuperAgent agentX;

    Agent* agentP = &agentX;
    agentP->setID(1337);
    agentX.setID(9999);

    agentX.print();
    return 0;
}
