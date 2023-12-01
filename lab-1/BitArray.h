#ifndef LAB_1_BITARRAY_H
#define LAB_1_BITARRAY_H

#include <cmath>
#include <string>

typedef unsigned short int Type;

class BitArray {
private:
    static const int bitPerBlock = (int) 8 * sizeof(Type);

    //current size in bits
    int currSizeInBite;

    //number of blocks are used
    int numberOfBlocks;

    //number of block are used in bits
    int numberOfBlockInBit;

    //array for keeping bites
    Type *array;

    class Bit {
    private:
        BitArray *bitArray;
        int index;
    public:
        bool value;
        //конструктор
        Bit(BitArray *bitAr, int i);

        // Оператор присваивания
        Bit& operator=(bool val);

        // Конструктор копирования
        Bit(const Bit &b);

        //Copy Assignment Operator // Оператор присваивания
        Bit &operator=(const Bit &b);

        operator bool() {
            return this->value;
        }
    };
public:
    //creates bitarray with num_bits elements, first  elements are initialised as value
    //int num_bits
    //unsigned long value = 0
    explicit BitArray(int num_bits, unsigned long value = 0);

    // copy constructor
    BitArray(const BitArray& b);
    //creates empty array reserving memory with size of Type
    BitArray();
    //clears allocated memory
    ~BitArray();

    //swaps two arrays, arrays can differ at size
    void swap(BitArray& b);
    //Copy Assignment Operator // Оператор присваивания
    BitArray& operator=(const BitArray& b);



    //Changes the size of the array. In case of expansion,
    //new elements are initialized with the value 'value'
    //int num_bits
    //bool value = false
    void resize(int num_bits, bool value = false);

    //Clears the array without changing its size
    void clear();

    //add new element to the end of the array
    //If necessary memory is redistributed
    //bool bit
    void push_back(bool bit);

    //Bitwise AND, changes original array, array can differ at size
    BitArray& operator&=(const BitArray& b);
    //Bitwise OR, changes original array, array can differ at size
    BitArray& operator|=(const BitArray& b);
    //Bitwise XOR, changes original array, array can differ at size
    BitArray& operator^=(const BitArray& b);

    //Bitwise left shift, changes original array
    BitArray& operator<<=(int n);
    //Bitwise right shift, changes original array
    BitArray& operator>>=(int n);

    //Bitwise left shift, create new object
    BitArray operator<<(int n) const;
    //Bitwise right shift, create new object
    BitArray operator>>(int n) const;


    //sets the bit with index n to val
    BitArray& set(int n, bool val = true);
    //fills the array with the true(the first size() bits)
    BitArray& set();

    //sets the bit with index n to false
    BitArray& reset(int n);
    //fills the array with the false(the first size() bits)
    BitArray& reset();

    //true if the array contains a true bit
    bool any() const;
    //true if all the bits of the array are false
    bool none() const;

    //Bit inversion
    BitArray operator~() const;
    //Counts the number of true bits
    int count() const;


    //changes/returns the value of the bit at the index i
    //changes: if i is larger than the size of the array, the size increases
    //returns: if i is larger than the size of the array, it returns an error
    Bit operator[](int i);

    //Returns the value of the bit at the index i
    //works as operator[], but only for reading
    //if i is larger than the size of the array, it returns an error
    bool operator()(int i) const;


    //returns amount of bits, used in array
    int size() const;
    //return true if size is 0
    bool empty() const;

    //returns the string representation of the array
    std::string to_string() const;

};

//returns true if arrays are equal
//(const BitArray & a, const BitArray & b);
bool operator==(const BitArray & a, const BitArray & b);

//returns true if arrays are different
//(const BitArray &a, const BitArray & b)
bool operator!=(const BitArray &a, const BitArray & b);
//Bitwise AND, returns new object
//(const BitArray &a, const BitArray & b);
BitArray operator&(const BitArray& b1, const BitArray& b2);

//Bitwise OR, returns new object
//(const BitArray & a, const BitArray & b);
BitArray operator|(const BitArray& b1, const BitArray& b2);

//Bitwise XOR, returns new object
//(const BitArray & a, const BitArray & b);
BitArray operator^(const BitArray& b1, const BitArray& b2);

#endif //LAB_1_BITARRAY_H
