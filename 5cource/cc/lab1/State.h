#ifndef STATE_H
#define STATE_H
#include <algorithm>
#include <map>
#include <memory>
#include <set>
#include <vector>
class State;
class NkaState;
using StatePtr = std::shared_ptr<State>;
using StateNkaPtr = std::shared_ptr<NkaState>;

//class NkaState {
//public:
//    NkaState() {}
//    void moveOnChar(char character, const StateNkaPtr& destinationState);

//public:
//    std::set<uint32_t> positions;
//    std::multimap<char, StateNkaPtr> charMultiTransitions;
//    bool isFinalState = false;
//    bool operator==(const NkaState& state) const;
//};
class State /*: public NkaState*/ { //should be template :0
public:
    State() {}
    void moveOnChar(char character, const StatePtr& destinationState, bool simulateMap = true);

public:
    std::set<uint32_t> positions;
    std::multimap<char, StatePtr> charTransitions;
    bool isFinalState = false;
    bool operator==(const State& state) const;
};

inline std::string setToString(const std::set<uint32_t>& set)
{
    std::string result;
    result += "{";
    for (auto& s : set) {
        result += std::to_string(s) + ",";
    }
    result += "}";
    size_t lastPos = result.find_last_of(','); // )))))
    if (lastPos != std::string::npos) {
        result.erase(lastPos, 1);
    }
    return result;
}

#endif // STATE_H
