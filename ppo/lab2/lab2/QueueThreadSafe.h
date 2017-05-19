#ifndef QUEUETHREADSAFE_H
#define QUEUETHREADSAFE_H
#include <Queue.h>
#include <mutex>

class QueueThreadSafe
{
public:
    QueueThreadSafe();
    void enqueue(int value);
    void dequeue();
    QVector<int> getItems();

private:
    Queue queue;
   std::mutex m_mutex;
};

#endif // QUEUETHREADSAFE_H
