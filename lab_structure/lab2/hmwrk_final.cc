#include "hmwrk.h"
#include <iostream>

int main(){
    DynemicArray arr(9);
    arr.push_front(4);
    arr.push_front(3);
    arr.printData();
    std::cout << arr.front() << std::endl;
    std::cout << arr.back() << std::endl;
    arr.insert(2,6);
    arr.printData();
    arr.dilit(0);
    arr.printData();
    arr.erase_after(3);
    arr.printData();
    arr.push_front(9);
    arr.push_front(8);
    arr.printData();
    arr.decrease_capacity(4);
    arr.printData();
    return 0;
}
