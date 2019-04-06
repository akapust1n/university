#ifndef STATE_H
#define STATE_H
#include <algorithm>
#include <map>
#include <memory>
#include <set>
#include <vector>
class State;
using StatePtr = std::shared_ptr<State>;

class State {
public:
    State() {}
    void moveOnChar(char character, const StatePtr& destinationState);

public:
    std::set<uint32_t> positions;
    std::map<char, StatePtr> charTransitions;
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
