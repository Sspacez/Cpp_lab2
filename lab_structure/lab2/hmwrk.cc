#include "hmwrk.h"

#include <cstdlib>
#include <exception>
#include <stdexcept>
#include <iostream>

DynemicArray::DynemicArray(std::int64_t capacity){
    if (capacity < 0) {
        throw std::invalid_argument("Capacity < 0");
    }
    this->capacity = capacity;
    data = new float[capacity];
}

DynemicArray::~DynemicArray(){
    delete[] data;
}

void DynemicArray::push_front(float x) {
    if (size == capacity) {
        std::int64_t newCapacity = capacity * 2;
        float* temp = new float[newCapacity];
        for (int i = 0; i < size; ++i) {
            temp[i + 1] = data[i];
        }
        delete[] data;
        data = temp;
        capacity = newCapacity;
    } else {
        for (int i = size; i > 0; --i) {
            data[i] = data[i - 1];
        }
    }
    data[0] = x;
    ++size;
}

float DynemicArray::front(){
    if (isEmpty()) {
        throw std::invalid_argument("Empty array");
    }
    return data[0];
}

float DynemicArray::back(){
    if (isEmpty()) {
        throw std::invalid_argument("Empty array");
    }
    return data[size - 1];
}

void DynemicArray::insert(std::int64_t idx, float x) {
    if (idx < 0 || idx > size) {
        throw std::out_of_range("Index out of bounds");
    }

    if (size == capacity) {
        std::int64_t newCapacity = capacity * 2;
        float* temp = new float[newCapacity];
        for (int i = 0; i < idx; ++i) {
            temp[i] = data[i];
        }
        temp[idx] = x;
        for (int i = idx; i < size; ++i) {
            temp[i + 1] = data[i];
        }
        delete[] data;
        data = temp;
        capacity = newCapacity;
    } else {
        for (int i = size; i > idx; --i) {
            data[i] = data[i - 1];
        }
        data[idx] = x;
    }
    ++size;
}

void DynemicArray::dilit(std::int64_t idx) {
    if (idx < 0 || idx >= size) {
        throw std::out_of_range("Index out of range");
    }
    for (int i = idx; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size;
}

void DynemicArray::erase_after(std::int64_t idx) {
    if (idx < 0 || idx >= size) {
        throw std::out_of_range("Index out of range");
    }
    size = idx + 1;
}

void DynemicArray::increase_capacity(std::int64_t newCapacity){
    if (newCapacity <= capacity) {
        return;
    }
    float* temp = new float[newCapacity];
    for (int i = 0; i < size; ++i) {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    capacity = newCapacity;
}

void DynemicArray::decrease_capacity(std::int64_t newCapacity){
    if (newCapacity >= capacity) {
        return;
    }
    if (newCapacity < size) {
        size = newCapacity;
    }
    float* temp = new float[newCapacity];
    for (int i = 0; i < size; ++i) {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    capacity = newCapacity;
}

void DynemicArray::printData() {
    for (int i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}
