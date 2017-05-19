#include "Stack.h"
#include <vector>
#include <algorithm>
#include <iostream>

Stack::Stack()
{
}

void Stack::push(int value)
{
    if (items.isEmpty()) {
        items.push_back(std::make_tuple(value, value, value));
    } else {
        int min = std::min(value, std::get<1>(items.last()));
        int max = std::max(value, std::get<2>(items.last()));

        items.push_back(std::make_tuple(value, min, max));
    }
}

int Stack::pop()
{
    if (items.isEmpty())
        return -1;
    int result = std::get<0>(items.back());
     items.pop_back();
    return result;
}

int Stack::size() const
{
    return items.size();
}

std::vector<int> Stack::getVector() const
{
    std::vector<int> result;
    auto begin = items.begin();
    auto end = items.end();
    end--;
    for (auto i =end; i>=begin; i--) {
        result.push_back(std::get<0>(*i));
    }
    return  result;
}

Item Stack::top() const
{
    return items.back();
}

bool Stack::isEmpty() const
{
    return items.isEmpty();
}

int Stack::min() const
{
    return std::get<1>(items.back());
}

int Stack::max() const
{
    return std::get<2>(items.back());
}
