#include "BitArray.h"
#include <cmath>
#include <iostream>
#include <cstdlib>


BitArray::BitArray(int num_bits, unsigned long value) {
    if (num_bits <= 0) {
        std::cout << "num_bits you put is wrong /n now num_bits = " << bitPerBlock << "bit";
    }
    currSizeInBite = num_bits;
    numberOfBlocks = (num_bits + bitPerBlock - 1) / bitPerBlock;
    numberOfBlockInBit = numberOfBlocks * bitPerBlock;
    array = new Type[numberOfBlocks];
    for (size_t i = 0; i < numberOfBlocks; ++i)
        array[i] = 0;
    Type a = 0;
    int valueInBlock = (int) pow(2, (int) 8 * sizeof(Type));
    for (size_t i = 0; i < numberOfBlocks; ++i) {
        a = value % valueInBlock;
        array[i] = a;
        value /= valueInBlock;
    }
}


BitArray::BitArray() {
    currSizeInBite = 0;
    numberOfBlocks = 1;
    numberOfBlockInBit = numberOfBlocks * bitPerBlock;
    array = new Type[numberOfBlocks];
    array[0] = 0;
}

BitArray::~BitArray() {
    delete array;
}


// Конструктор копирования
BitArray::BitArray(const BitArray &b) {
    if (*this == b) {
        return;
    }
    currSizeInBite = b.currSizeInBite;
    numberOfBlocks = b.numberOfBlocks;
    numberOfBlockInBit = b.numberOfBlockInBit;
    array = new Type[numberOfBlocks];
    /*for(int i = 0; i < currSizeInBite; ++i){
        set(i, b(i));
    }*/
    for (int i = 0; i < numberOfBlocks; ++i) {
        array[i] = b.array[i];
    }
}

void BitArray::swap(BitArray &b) {
    if (*this == b) {
        return;
    }
    BitArray temp = *this;
    *this = b;
    b = temp;
    //std::swap(this->currSizeInBite, b.currSizeInBite);
    //std::swap(this->numberOfBlocks, b.numberOfBlocks);
    //std::swap(this->numberOfBlockInBit, b.numberOfBlockInBit);
}


//Copy Assignment Operator
BitArray &BitArray::operator=(const BitArray &b) {
    if (this == &b) {
        return *this;
    }

    this->clear();
    for (int i = 0; i < b.currSizeInBite; i++) {
        this->push_back(b(i));
    }
    return *this;
}


void BitArray::resize(int num_bits, bool value) {
    if (num_bits <= 0) {
        throw std::runtime_error("number of bits must be positive");
    }
    size_t oldSize = currSizeInBite;
    size_t newSizeInBlock = (num_bits + bitPerBlock - 1) / bitPerBlock;
    Type *ptr = (Type *) realloc(this->array, newSizeInBlock);
    if (ptr == nullptr) {
        throw std::runtime_error("not enough memory is available");
    }
    this->array = ptr;
    this->numberOfBlocks = (int) newSizeInBlock;
    this->numberOfBlockInBit = (int) newSizeInBlock * bitPerBlock;
    this->currSizeInBite = num_bits;
    for(int i = (int) oldSize; i < this->numberOfBlockInBit; ++i) {
        set(i, value);
    }
}


BitArray &BitArray::operator<<=(int n) {
    for (int i = this->currSizeInBite; i >= 0 ; --i) {
        set(i, i - n >= 0 && (*this)(i - n));
    }
    return *this;
}

BitArray &BitArray::operator>>=(int n) {
    for (int i = 0; i < this->currSizeInBite ; ++i) {
        set(i, i + n < this->currSizeInBite && (*this)(i + n));
    }
    return *this;
}

BitArray BitArray::operator<<(int n) const {
    auto tmp = *this;
    tmp <<= n;
    return tmp;
}

BitArray BitArray::operator>>(int n) const {
    auto tmp = *this;
    tmp >>= n;
    return tmp;
}

BitArray &BitArray::set(int n, bool val) {
    if (n >= numberOfBlockInBit ) {
        resize(n + 1);
    }
    size_t iBlock = n / bitPerBlock;
    Type iBit = n % bitPerBlock;
    Type a = array[iBlock];
    if (val) {
        a = a | ((Type) 1 << iBit);
    } else {
        a = a & ~((Type) 1 << iBit);
    }
    array[iBlock] = a;
    return *this;
}

BitArray &BitArray::set() {
    for(int i = 0; i < this->currSizeInBite; ++i) {
        this->set(i, true);
    }
    return *this;
}

BitArray &BitArray::reset(int n) {
    this->set(n, false);
    return *this;
}

BitArray &BitArray::reset() {
    for(int i = 0; i < this->currSizeInBite; ++i) {
        this->set(i, false);
    }
    return *this;
}

void BitArray::clear() {
    /*for (size_t i = 0; i < numberOfBlocks; ++i) {
        array[i] = 0;
    }*/
    this->currSizeInBite = 0;
}

void BitArray::push_back(bool bit) {
    if (currSizeInBite == numberOfBlockInBit) {
        int oldSize = currSizeInBite;
        resize(2 * numberOfBlockInBit);
        currSizeInBite = oldSize;
    }
    this->set(currSizeInBite, bit);
    this->currSizeInBite++;
}

BitArray::Bit BitArray::operator[](int i) {
    if (i >= currSizeInBite) {
        resize(i + 1);
    }
    if (i < 0) {
        throw std::runtime_error("negative index");
    }
    return Bit(this, i);
}

bool BitArray::operator()(int i) const {
    if (i < 0 || i >= currSizeInBite || currSizeInBite == 0) {
        throw std::runtime_error("invalid index");
    }
    size_t iBlock = i / bitPerBlock;
    Type iBit = i % bitPerBlock;
    Type a = array[iBlock];
    return  a & ((Type) 1 << iBit);
}

int BitArray::size() const {
    return this->currSizeInBite;
}

bool BitArray::empty() const {
    return this->currSizeInBite == 0;
}

bool BitArray::any() const {
    for (size_t i = 0; i < this->numberOfBlocks; ++i) {
        if (this->array[i] != 0) {
            return true;
        }
    }
    return false;
}

bool BitArray::none() const {
    return !(this->any());
}

int BitArray::count() const {
    int sum = 0;
    for (size_t i = 0; i < currSizeInBite; ++i) {
        sum += (*this)(i);
    }
    return sum;
}

std::string BitArray::to_string() const {
    std::string str;
    for (int i = currSizeInBite - 1; i >= 0 ; --i) {
        str += (*this)(i) ? "1" : "0";
    }
    return str;
}

//Битовая инверсия
BitArray BitArray::operator~() const {
    auto res = BitArray(*this);
    for (int i = 0; i < res.currSizeInBite; ++i) {
        res.set(i, !((*this)(i)));
    }
    return res;
}

BitArray &BitArray::operator&=(const BitArray &b) {
    int min_size = this->size() <= b.size() ? this->size() : b.size();
    for (int i = 0; i < min_size; ++i) {
        *((Type *) array + i) &= *((Type *) b.array + i);
    }
    for (int i = min_size; i < this->size(); ++i) {
        *((Type *) array + i) = 0;
    }
    return *this;
}

BitArray &BitArray::operator|=(const BitArray &b) {
    int min_size = this->size() <= b.size() ? this->size() : b.size();
    for (int i = 0; i < min_size; ++i) {
        *((Type *) array + i) |= *((Type *) b.array + i);
    }
    return *this;
}

BitArray &BitArray::operator^=(const BitArray &b) {
    int min_size = this->size() <= b.size() ? this->size() : b.size();
    for (int i = 0; i < min_size; ++i) {
        *((Type *) array + i) ^= *((Type *) b.array + i);
    }
    return *this;
}

BitArray::Bit::Bit(BitArray *bitAr, int i) {
    this->bitArray = bitAr;
    this->index = i;
    value = (*bitAr)(i);
}

BitArray::Bit &BitArray::Bit::operator=(bool val) {
    bitArray->set(index, val);
    return *this;
}

BitArray::Bit::Bit(const BitArray::Bit &b) {
    bitArray = b.bitArray;
    value = b.value;
    index = b.index;
}

BitArray::Bit &BitArray::Bit::operator=(const BitArray::Bit &b) {
    value = b.value;
    index = b.index;
    return *this;
}

bool operator==(const BitArray & a, const BitArray & b) {
    if (a.size() != b.size())
        return false;
    int size = a.size();
    for (int i = 0; i < size; ++i) {
        if (a(i) != b(i))
            return false;
    }
    return true;
}

bool operator!=(const BitArray & a, const BitArray & b) {
    return !(a == b);
}

//Bitwise AND, returns new object
BitArray operator&(const BitArray& b1, const BitArray& b2) {
    auto tmp = b1;
    tmp &= b2;
    return tmp;
}

//Bitwise OR, returns new object
BitArray operator|(const BitArray& b1, const BitArray& b2) {
    auto tmp = b1;
    tmp |= b2;
    return tmp;
}

BitArray operator^(const BitArray& b1, const BitArray& b2) {
    auto tmp = b1;
    tmp ^= b2;
    return tmp;
}