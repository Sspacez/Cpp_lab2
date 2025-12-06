#ifndef STACK_H
#define STACK_H

#include "hmwrk.h"
#include <stdexcept>

template<typename T>
class Stack {
private:
    DynemicArray arr;
    std::int64_t maxSize;

public:
    Stack(std::int64_t maxSize);

    void push(const T& x);
    T pop();
    T top() const;
    bool isEmpty() const;
};

#include "stack.cc"

#endif
