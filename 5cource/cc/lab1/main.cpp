#include <DKA.h>
#include <State.h>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
int main()
{
    //build DKA
    //std::cout << "Input regex" << std::endl
    //        << ">";
    std::string regex = "(a|b)*abb";
    //std::cin >> regex;
    DKA dka(regex);
    if (!dka.IsValid()) {
        std::cout << "invalid regex";
    }
    auto FA = dka.buildDka();
    auto states = FA.states();
    for (auto& state : states) {
        std::cout << setToString(state->positions) << std::endl;
    }
    FA.visualize(dka.GetDot(FA), "dka");
    const std::string dotString = dka.GetDot(FA);

    return 0;
}
