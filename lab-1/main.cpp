#include <iostream>
#include "BitArray.h"


int main() {
    BitArray a =  BitArray(10, 19);

    BitArray b = a;

    std::cout <<"\n";
    for (int i = b.size() - 1; i >= 0; --i) {
        std::cout << b(i) << " ";
    }
    std::cout << "aaa";
    for (int i = a.size() - 1; i >= 0; --i) {
        std::cout << a[i] << " ";
    }
    return 0;
}
