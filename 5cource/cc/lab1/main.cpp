#include "Brzozowski.h"
#include "DKA.h"
#include "State.h"
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

int main()
{
    using namespace Brzozowski;
    //build DKA
    std::cout << "Input regex" << std::endl
              << ">";
    std::string regex;
    std::cin >> regex;
    //std::string regex = "(a|b)*abb";

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

    Automatia newFA = fa_rev(FA);
    newFA.visualize(dka.GetDot(newFA), "dka_rev");

    Automatia minFA = dr(dr(FA));
    minFA.visualize(dka.GetDot(minFA), "fa_min");

    std::cout << "\n----------------\n";
    while (1) {
        std::cout << "Regex for test: ";
        std::cin >> regex;
        regex += "#";
        if (FA.checkRegex(regex)) {
            std::cout << "valid\n";
        } else {
            std::cout << "invalid\n";
        }
    }

    return 0;
}
