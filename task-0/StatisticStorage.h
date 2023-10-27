//
// Created by PC on 19.10.2023.
//

#ifndef TASK_0_STATISTICSTORAGE_H
#define TASK_0_STATISTICSTORAGE_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

class StatisticStorage {
private:
    std::map<std::string, int> statistic;
    double totalNumber = 0;
    int numberOfUniqueWords = 0;
    std::vector<std::pair<std::string, int>> sortedStatistic();
public:
    void addElement(const std::string& str);

    double getTotalNumber() const {
        return totalNumber;
    }

    std::map<std::string, int> getStatistic() const {
        return statistic;
    }
    std::vector<std::pair<std::string, int>> getSortedStatistic() {
        return this->sortedStatistic();
    }
};


#endif //TASK_0_STATISTICSTORAGE_H
