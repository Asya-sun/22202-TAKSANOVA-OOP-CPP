//
// Created by PC on 19.10.2023.
//

#include "../StatisticStorage.h"
#include <map>
#include <string>
#include <vector>
#include <algorithm>


void StatisticStorage::addElement(const std::string &str) {
    statistic[str]++;
    if (statistic[str] == 1) {
        numberOfUniqueWords++;
    }
    totalNumber++;
}

std::vector<std::pair<std::string, int>> StatisticStorage::sortedStatistic() {
    std::vector< std::pair<std::string, int> > vectorStatistic(statistic.begin(), statistic.end());

    sort(vectorStatistic.begin(), vectorStatistic.end(),
         [](const std::pair<std::string, int>& p1, const std::pair<std::string, int>& p2) {
             // сначала сравниваем частоты по убыванию, потом — слова по возрастанию
             return tie(p2.second, p1.first) < tie(p1.second, p2.first);
         });

    return vectorStatistic;
}