#include <gtest/gtest.h>
#include "../StatisticStorage.h"
#include "../service/StatisticStorage.cpp"
#include <map>
#include <vector>
#include <utility>

TEST(StatisticStorageTest, 1) {
std::vector<std::string> words = {"a", "a", "a", "a", "b"};
StatisticStorage statistics;
for (auto const &word : words) {
statistics.addElement(word);
}
std::map<std::string, int> res = {{"a", 4}, {"b", 1}};
EXPECT_EQ(res, statistics.getStatistic());
}

TEST(StatisticStorageTest, 2) {
std::vector<std::string> words = {"x", "y", "w", "z"};
StatisticStorage statistics;
for (auto const &word : words) {
statistics.addElement(word);
}
std::map<std::string, int> res = {{"x", 1}, {"y", 1}, {"w", 1}, {"z", 1}};
EXPECT_EQ(res, statistics.getStatistic());
}