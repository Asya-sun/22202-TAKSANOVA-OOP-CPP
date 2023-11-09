#include <gtest/gtest.h>
#include "../CSVFileWriter.h"
#include "../service/CSVFileWriter.cpp"
#include "../service/CSVFileWriter.cpp"
#include <fstream>
#include <vector>
#include <string>


TEST(CSVFileWriter, writeLine1) {
    std::string word = "test";
    CSVFileWriter writer("test.txt");
    writer.open();
    writer.writeLine(word);
    std::ifstream file("test.txt");
    std::string res;
    file >> res;
    EXPECT_EQ(res, word);
}

TEST(CSVFileWriter, writeLine2) {
    std::vector<std::string> words = {"word1", "word2"};
    CSVFileWriter writer("test.txt");
    writer.open();
    writer.writeLine(words);
    std::ifstream file("test.txt");
    std::vector<std::string> res;
    while (!file.eof()) {
        std::string line;
        file >> line;
        if (!line.empty()) {
            res.push_back(line);
        }
    }
    EXPECT_EQ(res, words);
}