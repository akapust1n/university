#include "Queue.h"
#include <Stack.h>
#include <thread>
#include <tuple>

Queue::Queue()
{
}

void Queue::enqueue(int value)
{
    in.push(value);
}

void Queue::dequeue()
{
    if (out.isEmpty() and in.isEmpty())
        return;
    if (out.isEmpty()) {
        while (in.isEmpty())
            out.push(in.pop());
    }
   // out.pop();
}

int Queue::size() const
{
    return in.size() + out.size();
}

QVector<int> Queue::getItems() const
{
    QVector<int> result;
    auto reverse = [](QStack<Item> items) {
        QVector<int> result;
        for (auto item : items)
            result.push_front(std::get<0>(item));
        return result;
    };

    for (auto i : in.items)
        result.append(std::get<0>(i));

    auto temp = reverse(out.items);
    for (auto i : temp) {
        result.push_back(i);
    }
    return  result;
}

int Queue::minimum() const
{
    if (in.isEmpty() and out.isEmpty())
        return -1;
    if (in.isEmpty() or out.isEmpty())
        if (in.isEmpty())
            return std::get<1>(out.top());
    return std::get<1>(in.top());

    return std::max(std::get<1>(out.top()), std::get<1>(in.top()));}

int Queue::maximum() const
{
    if (in.isEmpty() and out.isEmpty())
        return -1;
    if (in.isEmpty() or out.isEmpty())
        if (in.isEmpty())
            return std::get<2>(out.top());
    return std::get<2>(in.top());

    return std::max(std::get<2>(out.top()), std::get<2>(in.top()));
}
