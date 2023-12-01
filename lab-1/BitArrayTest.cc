#include <gtest/gtest.h>
#include "BitArray.h"
#include "BitArray.cpp"
#include <string>


TEST(BitArray, copyConstructor) {
BitArray a = BitArray(3,6);
BitArray b = a;
for (int i = 0; i <= a.size() - 1; ++i) {
EXPECT_TRUE(a(i) ==  b(i)) << "bitarray a and b differ at index " << i;
}
ASSERT_TRUE(a == b) << "COPY CONSTRUCTOR MAKES NOT EQUAL OBJECTS";
};

TEST(BitArray, copyAssignmentOperator) {
BitArray a = BitArray(3,6);
BitArray b;
b = a;
for (int i = 0; i <= a.size() - 1; ++i) {
EXPECT_EQ(a(i), b(i)) << "bitarray a and b differ at index " << i;
}
ASSERT_TRUE(a == b) << "COPY ASSIGNMENT CONSTRUCTOR MAKES NOT EQUAL OBJECTS";
};

TEST(BitArray, swap) {
BitArray a = BitArray(3, 2);
BitArray b = BitArray(4, 5);
BitArray b1 = b;
BitArray a1 = a;
a.swap(b);
EXPECT_TRUE(a.size() == 4);
EXPECT_TRUE(b.size() == 3);
EXPECT_TRUE(a == b1);
EXPECT_TRUE(b == a1);
};


TEST(BitArray, bitShift) {
BitArray a = BitArray(3, 7);
BitArray a1 = BitArray(3, 6);
a <<= 1;
EXPECT_TRUE(a == a1);
a = a << 1;
a1[1] = false;
EXPECT_TRUE(a == a1);
BitArray b = BitArray(3, 7);
BitArray b1 = BitArray(3, 1);
b >>= 2;
EXPECT_TRUE(b == b1);
b = b >> 1;
b1[0] = false;
EXPECT_TRUE(b == b1);
}


TEST(BitArray, bitOperations) {
BitArray a = BitArray(3, 7);
BitArray b = BitArray(4, 6);
BitArray c = BitArray(3, 6);
a &= b;
EXPECT_TRUE(a == c);
a.set();
b |= a;
c.resize(4, false);
c.set(0, true);
EXPECT_TRUE(b == c);
c.reset(0);
b.reset();
b[0] = true;
b ^= a;
EXPECT_TRUE(b == c);
a.reset();
b.reset();
c = c & a;
EXPECT_TRUE(b == c);
c[0] = 1;
c[2] = 1;
a = c;
c = c | b;
EXPECT_TRUE(a == c);
a = a ^ c;
EXPECT_TRUE(a == b);
BitArray d = BitArray(3, 6);
BitArray e = BitArray(3, 1);
d = ~d;
EXPECT_TRUE(e == d);
EXPECT_FALSE(e != d);
}


TEST(BitArray, resize) {
BitArray a = BitArray(3, 4);
BitArray b = BitArray(4, 4);
a.resize(4);
EXPECT_TRUE(a == b);
a.resize(2);
BitArray c = BitArray(2, 0);
EXPECT_TRUE(a == c);
a.resize(5, true);
BitArray d = BitArray(5, 28);
EXPECT_TRUE(a == d);
}


TEST(BitArray, any) {
BitArray a = BitArray(3, 4);
EXPECT_TRUE(a.any());
}

TEST(BitArray, none) {
BitArray a = BitArray(3, 4);
EXPECT_FALSE(a.none());
a.reset();
EXPECT_TRUE(a.none());
}


TEST(BitArray, count) {
BitArray a = BitArray(3, 5);
EXPECT_TRUE(a.count() == 2);
a.reset();
EXPECT_TRUE(a.count() == 0);
}


TEST(BitArray, empty) {
BitArray a = BitArray(3, 5);
EXPECT_FALSE(a.empty());
a.clear();
EXPECT_TRUE(a.size() == 0);
EXPECT_TRUE(a.empty());
}


TEST(BitArray, toString) {
BitArray a = BitArray(4, 5);
std::string str = a.to_string();
EXPECT_EQ(str, "0101");
}


TEST(BitArray, pushBack) {
BitArray a = BitArray(4, 5);
a.push_back(true);
BitArray b = BitArray(5, 21);
for (int i = 0; i <= a.size() - 1; ++i) {
EXPECT_TRUE(a(i) ==  b(i)) << "bitarray a and b differ at index " << i;
}
a.push_back(false);
b.resize(6);
for (int i = 0; i <= a.size() - 1; ++i) {
EXPECT_TRUE(a(i) ==  b(i)) << "bitarray a and b differ at index " << i;
}
}



TEST(BitArray, Exceptions) {
BitArray a = BitArray(5, 6);
EXPECT_ANY_THROW(a.resize(-10));
EXPECT_ANY_THROW(a(-10));
EXPECT_ANY_THROW(a[-10]);
}
