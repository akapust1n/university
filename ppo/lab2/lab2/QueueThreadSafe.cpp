#include "QueueThreadSafe.h"

QueueThreadSafe::QueueThreadSafe()
{

}

void QueueThreadSafe::enqueue(int value)
{
     std::lock_guard<std::mutex> lock(m_mutex);
     queue.enqueue(value);

}

void QueueThreadSafe::dequeue()
{
    std::lock_guard<std::mutex> lock(m_mutex);
    queue.dequeue();

}

QVector<int> QueueThreadSafe::getItems()
{
    std::lock_guard<std::mutex> lock(m_mutex);
    return queue.getItems();

}
