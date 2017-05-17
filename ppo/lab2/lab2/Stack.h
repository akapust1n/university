#ifndef STACK_H
#define STACK_H
#include <QStack>
#include <tuple>

typedef std::tuple<int, int, int> Item;

class Stack {
public:
    Stack();
    void push(int value);
    int pop();
    Item top() const;
    bool isEmpty() const;
    int min() const;
    int max() const;
    int size() const;
    QStack<Item> items; //item-min-max


};

#endif // STACK_H
