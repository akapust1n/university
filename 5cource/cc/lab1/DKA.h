#ifndef TREEBUILDER_H
#define TREEBUILDER_H
#include "Automatia.h"
#include <limits>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <type_traits>
#include <vector>

struct RegexTreeEl;
using RegexTreeElPtr = std::shared_ptr<RegexTreeEl>;

const char skInvalidLetter = std::numeric_limits<char>::max();

struct RegexTreeEl {
    RegexTreeEl()
        : letter(skInvalidLetter)
        , position(std::numeric_limits<uint32_t>::max())
    {
    }
    RegexTreeEl(char _content, uint32_t _position = std::numeric_limits<uint32_t>::max())
        : letter(_content)
        , position(_position)
    {
    }
    RegexTreeEl(char _content, RegexTreeElPtr _leftChild, RegexTreeElPtr _rightChild,
        uint32_t _position = std::numeric_limits<uint32_t>::max())
        : letter(_content)
        , leftChild(_leftChild)
        , rightChild(_rightChild)
        , position(_position)
    {
    }
    RegexTreeElPtr addLeftChild(RegexTreeElPtr child);
    RegexTreeElPtr addRightChild(RegexTreeElPtr child);
    char letter;
    std::shared_ptr<RegexTreeEl> leftChild;
    std::shared_ptr<RegexTreeEl> rightChild;
    uint32_t position;
};

class DKA {
public:
    DKA(const std::string& regex);
    bool IsValid() const { return isValid; }

    RegexTreeElPtr getSyntaxTreeRoot() const;

private:
    RegexTreeElPtr parseRegex(const std::string& regex);
    std::string prepareRegex(const std::string& regex);
    void print(RegexTreeElPtr t, int32_t u);
    bool isValidSymbol(char symbol);
    bool isLetterOrDigit(char symbol);
    bool isOperation(char symbol);

    //ast
    RegexTreeElPtr getSum(std::string& regex);
    RegexTreeElPtr getProduct(std::string& regex);
    bool getElement(std::string& regex, char expected);
    RegexTreeElPtr getChar(std::string& regex);
    RegexTreeElPtr getIter(std::string& regex);

    //Dka build
    std::set<uint32_t> firstPos(const RegexTreeElPtr& node);
    std::set<uint32_t> lastPos(const RegexTreeElPtr& node);
    void followPos(const RegexTreeElPtr& node, std::map<uint32_t, std::set<uint32_t>>& result);
    bool nullable(const RegexTreeElPtr& node);
    std::map<uint32_t, std::set<uint32_t>> getFollowPosMap();

    std::vector<uint32_t> getPositions(RegexTreeElPtr root, char letter) const;

    std::string getPreparedRegex() const;
    bool stateInQ(const std::vector<StatePtr>& Q_unmarked, const std::vector<StatePtr>& Q_marked,
        StatePtr state, StatePtr& result);

public:
    Automatia buildDka();
    std::string GetDot(const Automatia& au) const;

private:
    bool isValid;
    const std::string operations;
    const std::string operationNeedDot;
    uint32_t position;
    RegexTreeElPtr syntaxTreeRoot;
    std::string preparedRegex;
};

#endif // TREEBUILDER_H
