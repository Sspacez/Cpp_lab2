#ifndef QUEUE_H
#define QUEUE_H

#include "stack.h"

template<typename T>
class Queue {
private:
    Stack<T> inStack;
    Stack<T> outStack;

public:
    Queue(std::int64_t maxSize);

    void enqueue(const T& x);
    T dequeue();
    bool isEmpty() const;
    std::int64_t size() const;
};

#include "queue.cc"

#endif
