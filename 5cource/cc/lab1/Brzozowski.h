#ifndef BRZOZOWSKI_H
#define BRZOZOWSKI_H
#include "Automatia.h"
#include <iostream>
#include <queue>
#include <stack>

namespace Brzozowski {
inline Automatia fa_rev(const Automatia& fa)
{
    auto states = fa.states();
    std::vector<StatePtr> copyStates;
    StatePtr startState;

    for (auto& state : states) {
        StatePtr temp = std::make_shared<State>(*state);
        temp->isFinalState = fa.getStartState() == state;
        temp->charTransitions.clear();
        if (state->isFinalState) {
            startState = temp;
        }
        copyStates.push_back(temp);
    }

    /*
    for (uint32_t i = 0; i < copyStates.size(); ++i) {
        for (uint32_t j = 0; j < states.size(); ++j) {
            if (i == j)
                continue;
            if(states[i]->positions)
            for(auto &[letter, state]: states[i]->charTransitions)
            {

            }
        }
    }*/
    for (auto& copyState : copyStates)
        for (auto& state : states) {
            //if (*copyState == *state)
            //  continue;
            for (auto& [letter, localState] : state->charTransitions) {
                if (*localState == *copyState) {
                    auto capturePass = state;
                    auto findPos = std::find_if(copyStates.cbegin(), copyStates.cend(),
                        [capturePass](const StatePtr& ptr) {
                            return *capturePass == *ptr;
                        });

                    if (findPos != copyStates.cend())
                        copyState->moveOnChar(letter, *findPos, false);
                }
            }
        }

    return Automatia(startState);
}
inline uint32_t getPosOfStartState(const Automatia& FA)
{
    auto tempStates = fa_rev(FA).states();
    return tempStates.size() < 2 or !tempStates[0]->isFinalState ? 0 : 1;
}
inline Automatia dr(const Automatia& FA)
{
    Automatia au = Automatia(fa_rev(FA).states()[getPosOfStartState(FA)]);
    //Automatia(fa_rev(Automatia(fa_rev(FA).states()[startState])).states()[startState]);
    return au;
}
};

#endif // BRZOZOWSKI_H
