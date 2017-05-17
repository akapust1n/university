#ifndef QUEUE_H
#define QUEUE_H
#include <Stack.h>
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
};

#endif // QUEUE_H
