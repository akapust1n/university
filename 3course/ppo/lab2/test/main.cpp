#include "Queue.h"
#include <QtTest/QtTest>
#include <iostream>
#include <stack>

class TestQueue : public QObject {
    Q_OBJECT

private slots:
    void testMaximum()
    {
        Queue queue;
        queue.enqueue(2);
        queue.enqueue(33);
        queue.enqueue(1);
        queue.enqueue(3);
        queue.enqueue(8);
        queue.enqueue(14);

        QCOMPARE(queue.maximum(), 33);
    }
    void testMinimum()
    {
        Queue queue;
        queue.enqueue(3);
        queue.enqueue(3);
        queue.enqueue(2);
        queue.enqueue(8);
        queue.enqueue(14);
        queue.enqueue(33);
        QCOMPARE(queue.minimum(), 2);
    }

    void testEnqueue()
    {
        QVector<int> test({ 1, 3, 2, 8, 14, 33 });
        Queue queue;
        queue.enqueue(1);
        queue.enqueue(3);
        queue.enqueue(2);
        queue.enqueue(8);
        queue.enqueue(14);
        queue.enqueue(33);
        auto temp = queue.getItems();

        QCOMPARE(temp, test);
    }

    void testDequeue()
    {
        QVector<int> test({ 3, 2, 8, 14, 33 });
        Queue queue;
        queue.enqueue(1);
        queue.enqueue(3);
        queue.enqueue(2);
        queue.enqueue(8);
        queue.enqueue(14);
        queue.enqueue(33);
        queue.dequeue();

        auto temp = queue.getItems();

        QCOMPARE(temp, test);
    }

    void testSize()
    {
        QVector<int> test({ 1, 3, 2, 8, 14, 33 });
        Queue queue;
        queue.enqueue(1);
        queue.enqueue(3);
        queue.enqueue(2);
        queue.enqueue(8);
        queue.enqueue(14);
        queue.enqueue(33);

        auto temp = queue.getItems();

        QCOMPARE(temp.size(), test.size());
    }
};

QTEST_MAIN(TestQueue)
#include "main.moc"
