#include "Automatia.h"
#include <algorithm>
#include <graphviz/cgraph.h>
#include <graphviz/gvc.h>
#include <stack>

Automatia::Automatia(StatePtr _startState)
    : startState(_startState)
{
}

void Automatia::visualize(const std::string& dot, const std::string& filename)
{
    GVC_t* gvc = gvContext();
    Agraph_t* g = agmemread(dot.c_str());

    gvLayout(gvc, g, "dot");
    gvRender(gvc, g, "png", fopen((filename + ".png").c_str(), "w"));
    gvFreeLayout(gvc, g);
    agclose(g);
    gvFreeContext(gvc);
}

std::vector<StatePtr> Automatia::states() const
{
    std::vector<StatePtr> visited;
    std::stack<StatePtr> state_stack;
    state_stack.push(startState);
    while (state_stack.size()) {
        auto state = state_stack.top();
        state_stack.pop();
        if (std::find(visited.cbegin(), visited.cend(), state) == visited.cend()) {
            visited.push_back(state);
            for (auto& destinations : state->charTransitions) {
                if (!(destinations.second->positions.empty())
                    and (std::find(visited.cbegin(), visited.cend(), destinations.second)
                            == visited.cend())) {
                    state_stack.push(destinations.second);
                }
            }
        }
    }
    std::sort(visited.begin(), visited.end(),
        [](const StatePtr& a, const StatePtr& b) -> bool {
            return setToString(a->positions) < setToString(b->positions); // )))))))
        });
    return visited;
}

StatePtr Automatia::getStartState() const
{
    return startState;
}
