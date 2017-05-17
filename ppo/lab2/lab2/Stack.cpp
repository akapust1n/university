#include "Stack.h"

Stack::Stack()
{
}

void Stack::push(int value)
{
    if (items.isEmpty()) {
        items.push(std::make_tuple(value, value, value));
    } else {
        int min = std::get<1>(items.top());
        int max = std::get<2>(items.top());

        items.push(std::make_tuple(value, min, max));
    }
}

int Stack::pop()
{
    return std::get<0>(items.pop());
}

int Stack::size() const
{
    return  items.size();
}

Item Stack::top() const
{
    return items.top();

}

bool Stack::isEmpty() const
{
    return  items.isEmpty();

}

int Stack::min() const
{
    return std::get<1>(items.top());

}

int Stack::max() const
{
    return std::get<2>(items.top());


}
