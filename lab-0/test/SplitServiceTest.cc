#include <gtest/gtest.h>
#include "../SplitService.h"
#include "../service/SplitService.cpp"
#include <vector>

TEST(SplitService, 1) {
    SplitService splitter;
    auto words = splitter.parse("a, a, a, a");
    std::vector<std::string> res = {"a", "a", "a", "a"};
    EXPECT_EQ(words.size(), 4);
    EXPECT_EQ(res, words);
}

TEST(SplitService, 2) {
    SplitService splitter;
    auto words = splitter.parse("a, b/ c. d");
    std::vector<std::string> res = {"a", "b", "c", "d"};
    EXPECT_EQ(words.size(), 4);
    EXPECT_EQ(words, res);
}

TEST(SplitService, 3) {
    SplitService splitter;
    auto words = splitter.parse(" ");
    std::vector<std::string> res = {};
    EXPECT_EQ(words.size(), 0);
    EXPECT_EQ(words, res);
}

TEST(SplitService, 4) {
    SplitService splitter;
    auto words = splitter.parse("..|/,<>");
    std::vector<std::string> res = {};
    EXPECT_EQ(words.size(), 0);
    EXPECT_EQ(words, res);
}

TEST(SplitService, 5) {
    SplitService splitter;
    auto words = splitter.parse("a..|/,<d>d");
    std::vector<std::string> res = {"a", "d", "d"};
    EXPECT_EQ(words.size(), 3);
    EXPECT_EQ(words, res);
}

TEST(SplitService, 6) {
    SplitService splitter;
    auto words = splitter.parse("aaa..|/,<d>dd");
    std::vector<std::string> res = {"aaa", "d", "dd"};
    EXPECT_EQ(words.size(), 3);
    EXPECT_EQ(words, res);
}

TEST(SplitService, 7) {
    SplitService splitter;
    auto words = splitter.parse("aaa..|/,<d>dd,\n");
    std::vector<std::string> res = {"aaa", "d", "dd"};
    EXPECT_EQ(words.size(), 3);
    EXPECT_EQ(words, res);
}

TEST(SplitService, 8) {
    SplitService splitter;
    auto words = splitter.parse("");
    std::vector<std::string> res = {};
    EXPECT_EQ(words.size(), 0);
    EXPECT_EQ(words, res);
}

TEST(SplitService, 9) {
    SplitService splitter;
    auto words = splitter.parse("d..\t|\r/,<d>d,\n");
    std::vector<std::string> res = {"d", "d", "d"};
    EXPECT_EQ(words.size(), 3);
    EXPECT_EQ(words, res);
}