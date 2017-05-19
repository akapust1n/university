#include "Queue.h"
#include "/home/alexey/16/university/ppo/lab2/lab2/Stack.h"
#include <iostream>
#include <thread>
#include <tuple>
#include <algorithm>

Queue::Queue()
{
}

void Queue::enqueue(int value)
{
    if (size() < maxSize) {
        in.push(value);
    } else {
        dequeue();
        //  std::cout<<"SIZE"<<size()<<"__PUSHED "<<value<<std::endl;
        in.push(value);
    }
}

void Queue::dequeue()
{
    if (out.isEmpty() and in.isEmpty())
        return;
    if (out.isEmpty()) {
        while (!in.isEmpty())
            out.push(in.pop());
    }
    out.pop();
}

int Queue::size() const
{
    return in.size() + out.size();
}

QVector<int> Queue::getItems() const
{
    QVector<int> result;

    auto items = in.getVector();
    for (auto &i : items)
        result.append((i));

    auto temp = out.getVector();
    std::reverse(std::begin(temp),std::end(temp));

    for (auto &i :temp )
       result.append((i));

    std::reverse(std::begin(result),std::end(result));

    return result;
}

int Queue::minimum() const
{
    if (in.isEmpty() and out.isEmpty())
        return -1;
    if (in.isEmpty() or out.isEmpty())
        if (in.isEmpty())
            return std::get<1>(out.top());

    return std::min(std::get<1>(out.top()), std::get<1>(in.top()));
}

int Queue::maximum() const
{
    if (in.isEmpty() and out.isEmpty())
        return -1;
    if (in.isEmpty() or out.isEmpty())
        if (in.isEmpty())
            return std::get<2>(out.top());

    return std::max(std::get<2>(out.top()), std::get<2>(in.top()));
}
