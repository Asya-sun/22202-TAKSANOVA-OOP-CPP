//
// Created by PC on 19.10.2023.
//

#include "../SplitService.h"

std::vector<std::string> SplitService::parse(const std::string &str) {

    std::vector<std::string> result;
    std::regex re(regexpPattern);

    std::sregex_token_iterator iter(str.begin(),
                                    str.end(), re);
    std::sregex_token_iterator end;

    while (iter != end) {
        if (iter->length()) {
            result.push_back(*iter);
        }
        ++iter;
    }
    return result;

}