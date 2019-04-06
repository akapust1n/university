#include "DKA.h"
#include <algorithm>
#include <cctype>
#include <exception>
#include <iostream>
#include <map>

RegexTreeElPtr RegexTreeEl::addLeftChild(RegexTreeElPtr child)
{
    leftChild = child;
    return child;
}

RegexTreeElPtr RegexTreeEl::addRightChild(RegexTreeElPtr child)
{
    rightChild = child;
    return child;
}

DKA::DKA(const std::string& regex)
    : isValid(true)
    , operations("()*|.+")
    , endSymbol('#')
    , operationNeedDot("+*")
    , position(1)
{
    if (regex.length() == 0) {
        isValid = false;
    } else {
        syntaxTreeRoot = parseRegex(regex);
        if (syntaxTreeRoot) {
            print(syntaxTreeRoot, 0);
        }
    }
}

std::map<uint32_t, std::set<uint32_t>> DKA::getFollowPosMap()
{
    std::map<uint32_t, std::set<uint32_t>> followpos_result;
    followPos(syntaxTreeRoot, followpos_result);
    const uint32_t max = followpos_result.rbegin()->first + 1;
    followpos_result[max] = std::set<uint32_t>{};
    return followpos_result;
}

RegexTreeElPtr DKA::parseRegex(const std::string& regex)
{
    preparedRegex = prepareRegex(regex);
    if (!isValid)
        return nullptr;
    std::string preparedRegexCopy = preparedRegex;
    RegexTreeElPtr tree = getSum(preparedRegexCopy);
    return tree;
}

std::string DKA::prepareRegex(const std::string& regex)
{
    char prev = '#';
    std::string result;
    uint32_t bracketBalance = 0;
    for (auto elem : regex) {
        if (elem == '\0')
            continue;
        if (!isValidSymbol(elem)) {
            isValid = false;
            std::cout << "Invalid symbol" << std::endl;
            return std::string();
        }
        if ((isLetterOrDigit(prev) or operationNeedDot.find(prev) != std::string::npos)
            and (isLetterOrDigit(elem) or elem == '(')) {
            result += '.';
        }
        if (isLetterOrDigit(elem))
            ++position;

        result += elem;
        prev = elem;
        if (elem == '(')
            bracketBalance++;
        else if (elem == ')')
            bracketBalance--;
    }
    if (bracketBalance) {
        std::cout << "Invalid count of brackets!" << std::endl;
        isValid = false;
        return std::string();
    }
    result += ".#";
    ++position;
    std::reverse(result.begin(), result.end());
    return result;
}

void DKA::print(RegexTreeElPtr t, int32_t u)
{

    if (t == nullptr)
        return; //Если дерево пустое, то отображать нечего, выходим
    else //Иначе
    {
        print(t->leftChild, ++u); //С помощью рекурсивного посещаем левое поддерево
        for (int i = 0; i < u; ++i)
            std::cout << "@";
        std::cout << t->letter << std::endl; //И показываем элемент
        u--;
    }
    print(t->rightChild, ++u); //С помощью рекурсии посещаем правое поддерево
}
bool DKA::isValidSymbol(char symbol)
{
    return isLetterOrDigit(symbol) or isOperation(symbol);
}

bool DKA::isLetterOrDigit(char symbol)
{
    return isalpha(symbol) or isdigit(symbol);
}

bool DKA::isOperation(char symbol)
{
    return operations.find(symbol) != std::string::npos or operationNeedDot.find(symbol) != std::string::npos;
}

RegexTreeElPtr DKA::getSum(std::string& regex)
{
    RegexTreeElPtr a = getProduct(regex);
    if (getElement(regex, '.')) {
        RegexTreeElPtr b = getSum(regex);
        return RegexTreeElPtr(new RegexTreeEl('.', b, a));
    } else
        return a;
}

RegexTreeElPtr DKA::getProduct(std::string& regex)
{
    RegexTreeElPtr a = getIter(regex);
    if (getElement(regex, '|')) {
        RegexTreeElPtr b = getChar(regex);
        return RegexTreeElPtr(new RegexTreeEl('|', b, a));
    } else
        return a;
}

bool DKA::getElement(std::string& regex, char expected)
{
    /* Функция сравнивает ожидаемую лексему с первой в списке */
    if (regex.empty() or (regex[0] != expected))
        return false;

    regex.erase(regex.begin());
    return true;
}

RegexTreeElPtr DKA::getChar(std::string& regex)
{
    /* Формирует вершину дерева из первого элемента списка, если тот не является операндом*/
    if (getElement(regex, ')')) {
        RegexTreeElPtr x = getSum(regex);
        getElement(regex, '(');
        return x;
    } else {
        char x = regex[0];
        if (isOperation(x))
            return nullptr;
        regex.erase(regex.begin());
        --position;
        RegexTreeElPtr result(new RegexTreeEl(x, position));
        return result;
    }
}

RegexTreeElPtr DKA::getIter(std::string& regex)
{
    RegexTreeElPtr a = getChar(regex);
    if (getElement(regex, '*')) {
        RegexTreeElPtr b = getChar(regex);
        return RegexTreeElPtr(new RegexTreeEl('*', b, a));
    } else if (getElement(regex, '+')) {
        RegexTreeElPtr b = getChar(regex);
        RegexTreeElPtr rightChild(new RegexTreeEl('*', b, a));
        return RegexTreeElPtr(new RegexTreeEl('.', b, rightChild));
    } else
        return a;
}

std::set<uint32_t> DKA::firstPos(const RegexTreeElPtr& node)
{
    if (isLetterOrDigit(node->letter) or (node->letter == '#'))
        return { node->position };

    std::set<uint32_t> result;

    if (node->letter == '|') {
        auto letfUnion = firstPos(node->leftChild);
        auto rightUnion = firstPos(node->rightChild);
        std::set_union(letfUnion.begin(), letfUnion.end(),
            rightUnion.begin(), rightUnion.end(),
            std::inserter(result, result.begin()));

        return result;
    }
    if (node->letter == '.') {
        if (nullable(node->leftChild)) {
            auto letfUnion = firstPos(node->leftChild);
            auto rightUnion = firstPos(node->rightChild);
            std::set_union(letfUnion.begin(), letfUnion.end(),
                rightUnion.begin(), rightUnion.end(),
                std::inserter(result, result.begin()));
            return result;
        }
        return firstPos(node->leftChild);
    }
    if (node->letter == '*' or node->letter == '+')
        return firstPos(node->leftChild);
    return std::set<uint32_t>();
}

std::set<uint32_t> DKA::lastPos(const RegexTreeElPtr& node)
{
    if (isLetterOrDigit(node->letter) or (node->letter == '#'))
        return { node->position };

    std::set<uint32_t> result;

    if (node->letter == '|') {
        auto letfUnion = lastPos(node->leftChild);
        auto rightUnion = lastPos(node->rightChild);
        std::set_union(letfUnion.begin(), letfUnion.end(),
            rightUnion.begin(), rightUnion.end(),
            std::inserter(result, result.begin()));
        return result;
    }
    if (node->letter == '.') {
        if (nullable(node->rightChild)) {
            auto letfUnion = lastPos(node->leftChild);
            auto rightUnion = lastPos(node->rightChild);
            std::set_union(letfUnion.begin(), letfUnion.end(),
                rightUnion.begin(), rightUnion.end(),
                std::inserter(result, result.begin()));
            return result;
        }
        return lastPos(node->rightChild);
    }
    if (node->letter == '*' or node->letter == '+')
        return lastPos(node->leftChild);

    return std::set<uint32_t>();
}

void DKA::followPos(const RegexTreeElPtr& node, std::map<uint32_t, std::set<uint32_t>>& result)
{
    if (!node)
        return;
    followPos(node->leftChild, result);
    followPos(node->rightChild, result);

    if (node->letter == '.') {
        auto i_set = lastPos(node->leftChild);
        auto fpos = firstPos(node->rightChild);
        for (auto it = i_set.cbegin(); it != i_set.cend(); ++it) {
            result[*it].insert(fpos.cbegin(), fpos.cend());
        }
        return;
    }

    if (node->letter == '*') {
        auto i_set = lastPos(node->leftChild);
        auto fpos = firstPos(node->leftChild);
        for (auto it = i_set.cbegin(); it != i_set.cend(); ++it) {
            result[*it].insert(fpos.cbegin(), fpos.cend());
        }
        return;
    }
}

bool DKA::nullable(const RegexTreeElPtr& node)
{

    if (isLetterOrDigit(node->letter) or (node->letter == '#'))
        return false;
    if (node->letter == '|')
        return nullable(node->leftChild) or nullable(node->rightChild);
    if (node->letter == '.')
        return nullable(node->leftChild) and nullable(node->rightChild);
    if (node->letter == '*')
        return true;
    if (node->letter == '+')
        return false;

    return true;
}

std::vector<uint32_t> DKA::getPositions(RegexTreeElPtr root, char letter) const
{
    std::vector<uint32_t> result;

    if (!root)
        return result;
    if (root->letter == letter) {
        result.push_back(root->position);
    };
    auto leftTree = getPositions(root->leftChild, letter);
    result.insert(result.end(), leftTree.cbegin(), leftTree.cend());
    auto rightTree = getPositions(root->rightChild, letter);
    result.insert(result.end(), rightTree.cbegin(), rightTree.cend());
}

std::string DKA::getPreparedRegex() const
{
    return preparedRegex;
}

bool DKA::stateInQ(const std::vector<StatePtr>& Q_unmarked, const std::vector<StatePtr>& Q_marked, StatePtr state, StatePtr& result)
{
    for (auto s : Q_marked) {
        if (s->positions == state->positions) {
            result = s;
            return true;
        }
    }
    for (auto s : Q_unmarked) {
        if (s->positions == state->positions) {
            result = s;
            return true;
        }
    }
    result = state;
    return false;
}

Automatia DKA::buildDka()
{
    RegexTreeElPtr root = getSyntaxTreeRoot();

    auto followPosMap = getFollowPosMap();
    for (const auto& p : followPosMap) {
        std::cout << "m[" << p.first << "] ="
                  << setToString(p.second) << '\n';
    }
    std::cout << "Строим ДКА по регулярному выражению" << std::endl;
    StatePtr q0(new State);
    q0->positions = firstPos(root);
    std::vector<StatePtr> Q_unmarked;
    std::vector<StatePtr> Q_marked;
    std::cout << "Добавляем q0 в Q как непомеченное\n";

    Q_unmarked.push_back(q0);

    std::map<char, std::vector<uint32_t>> char_positions;
    const std::string preparedRegex = getPreparedRegex();
    for (auto it = preparedRegex.cbegin(); it != preparedRegex.cend(); ++it) {
        char_positions[*it] = getPositions(root, *it);
    }

    while (Q_unmarked.size()) {
        auto R = Q_unmarked.front();
        std::cout << "Берем непомеченное состояние" << setToString(R->positions) << "и помечаем его\n";

        Q_unmarked.erase(Q_unmarked.begin());
        Q_marked.push_back(R);

        for (auto it = preparedRegex.cbegin(); it != preparedRegex.cend(); ++it) {
            auto tempCharPositions = char_positions[*it];
            std::set<uint32_t> p;
            std::set_intersection(tempCharPositions.cbegin(), tempCharPositions.cend(),
                R->positions.cbegin(), R->positions.cend(), std::inserter(p, p.begin()));
            if (p.size()) {
                std::set<uint32_t> S_set;
                for (auto pi : p) {
                    auto fl = followPosMap[pi];
                    S_set.insert(fl.cbegin(), fl.cend());
                }
                if (S_set.size()) {
                    StatePtr S(new State);
                    S->positions = S_set;
                    StatePtr result;
                    bool in_Q = stateInQ(Q_unmarked, Q_marked, S, result);
                    if (!in_Q) {
                        Q_unmarked.push_back(result);
                    }
                    // определить D(R, a) = S;
                    R->moveOnChar(*it, result);
                }
            }
        }
    }
    // Определить F как множество всех состояний из Q, содержащих позиции, связанные с символом #
    uint32_t end_key_position = followPosMap.rbegin()->first;
    for (auto& state : Q_marked) {
        if (state->positions.count(end_key_position)) {
            state->isFinalState = true;
        }
    }
    return Automatia(Q_marked[0]);
}

std::string DKA::GetDot(const Automatia& au) const
{
    std::string result = "digraph {\n";
    auto states = au.states();
    for (auto& state : states) {
        for (auto node : state->charTransitions) {
            result += '\"';
            result += setToString(state->positions);
            result += '\"';
            result += " -> ";
            result += '\"';
            result += setToString(node.second->positions);
            result += '\"';
            result += " [ label = \"";
            result += node.first;
            result += "\" ]\n";
        }
    }
    result += "}";
    std::cout << result;
    return result;
}

RegexTreeElPtr DKA::getSyntaxTreeRoot() const
{
    return syntaxTreeRoot;
}
