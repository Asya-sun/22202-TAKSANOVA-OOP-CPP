//
// Created by PC on 19.10.2023.
//

#ifndef TASK_0_SPLITSERVICE_H
#define TASK_0_SPLITSERVICE_H

#include <string>
#include <vector>
#include <regex>


class SplitService {

public:

    std::string regexpPattern;

    SplitService() {
        regexpPattern = "\\w+";
    }

    std::vector<std::string> parse(const std::string& str);
};

#endif //TASK_0_SPLITSERVICE_H
