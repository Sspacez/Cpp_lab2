#ifndef HMWRK_H
#define HMWRK_H

#include <cstdint>

class DynemicArray {
private:
    float* data;
    std::int64_t size = 0;
    std::int64_t capacity = 8;

    bool isEmpty(){
        return size == 0;
    }

public:
    DynemicArray(std::int64_t capacity);
    ~DynemicArray();

    void push_front(float x);
    void erase_after(std::int64_t idx);
    void increase_capacity(std::int64_t newCapacity);
    void decrease_capacity(std::int64_t newCapacity);
    float front();
    float back();
    void insert(std::int64_t idx, float x);
    void dilit(std::int64_t idx);
    void printData();
};

#endif
