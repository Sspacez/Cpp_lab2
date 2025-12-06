#ifndef QUEUE_CC
#define QUEUE_CC

#include "queue.h"

template<typename T>
Queue<T>::Queue(std::int64_t maxSize)
    : inStack(maxSize), outStack(maxSize) {}

template<typename T>
void Queue<T>::enqueue(const T& x) {
    inStack.push(x);
}

template<typename T>
T Queue<T>::dequeue() {
    if (outStack.isEmpty()) {
        while (!inStack.isEmpty()) {
            outStack.push(inStack.pop());
        }
    }
    if (outStack.isEmpty()) {
        throw std::underflow_error("Queue is empty");
    }
    return outStack.pop();
}

template<typename T>
bool Queue<T>::isEmpty() const {
    return inStack.isEmpty() && outStack.isEmpty();
}

template<typename T>
std::int64_t Queue<T>::size() const {

    throw std::logic_error("DynamicArray lacks size() method — cannot compute queue size()");
}

#endif
