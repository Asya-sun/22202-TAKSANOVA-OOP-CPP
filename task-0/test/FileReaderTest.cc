#include <gtest/gtest.h>
#include <fstream>
#include "../FileReader.h"

TEST(FileReader, getNext) {
std::ofstream file("test.txt");
file << "word";
file.close();
FileReader reader("test.txt");
reader.open();
std::string line = reader.getNext();
EXPECT_EQ("word", line);
}

TEST(FileReader, hasNext) {
std::ofstream file("test.txt");
file << "word";
file.close();
FileReader reader("test.txt");
reader.open();
std::string line = reader.getNext();
EXPECT_EQ(false, reader.hasNext());
}

TEST(FileReader, reset) {
std::ofstream file("test.txt");
file << "word";
file.close();
FileReader reader("test.txt");
reader.open();
reader.getNext();
reader.reset();
EXPECT_EQ("word", reader.getNext());
}

TEST(FileReader, isOpen) {
FileReader reader("test.txt");
EXPECT_EQ(false, reader.isOpen());
}