//
// Created by PC on 08.11.2023.
//

#ifndef LAB_0_SPLITSERVICE_H
#define LAB_0_SPLITSERVICE_H

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


#endif //LAB_0_SPLITSERVICE_H
