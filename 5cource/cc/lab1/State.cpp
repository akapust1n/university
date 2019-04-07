#include "State.h"

void State::moveOnChar(char character, const StatePtr& destinationState, bool simulateMap)
{
    if (simulateMap) {
        charTransitions.erase(character); // ))))))
    }
    charTransitions.insert({ character, destinationState });
}

bool State::operator==(const State& state) const
{
    return state.positions == positions;
    //and state.isFinalState == isFinalState  and state.charTransitions == charTransitions;
}

//void NkaState::moveOnChar(char character, const StateNkaPtr& destinationState)
//{
//    charMultiTransitions.insert({ character, destinationState });
//}

//bool NkaState::operator==(const NkaState& state) const
//{
//    return state.positions == positions;
//}
