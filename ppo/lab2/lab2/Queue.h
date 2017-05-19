#ifndef QUEUE_H
#define QUEUE_H
#include "/home/alexey/16/university/ppo/lab2/lab2/Stack.h"
#include <QVector>
class Queue {
public:
    Queue();
    void enqueue(int value);
    void dequeue();
    int minimum() const;
    int maximum() const;
    int size() const;
    QVector<int> getItems() const;

private:
    Stack in, out;
    int maxSize = 15;
};

#endif // QUEUE_H
