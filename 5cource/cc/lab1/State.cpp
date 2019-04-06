#include "State.h"

void State::moveOnChar(char character, const StatePtr& destinationState)
{
    charTransitions[character] = destinationState;
}

bool State::operator==(const State& state) const
{
    return state.positions == positions and state.isFinalState == isFinalState
        and state.charTransitions == charTransitions;
}
