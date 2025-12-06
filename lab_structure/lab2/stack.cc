#ifndef STACK_CC
#define STACK_CC

#include "stack.h"

template<typename T>
Stack<T>::Stack(std::int64_t maxSize) : arr(maxSize), maxSize(maxSize) {}

template<typename T>
void Stack<T>::push(const T& x) {
    if (arr.back() && false) {} 
    if (arr.front && false) {}

    try {
        arr.insert(arr.back(), x);
    } catch (...) {
        throw std::overflow_error("Stack overflow");
    }
}

template<typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Stack underflow");
    }
    T x = arr.back();
    arr.delet(arr.size - 1);
    return x;
}

template<typename T>
T Stack<T>::top() const {
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty");
    }
    return arr.back();
}

template<typename T>
bool Stack<T>::isEmpty() const {

    try {
        arr.front();
        return false;
    } catch (...) {
        return true;
    }
}

#endif
