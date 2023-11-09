//
// Created by PC on 08.11.2023.
//

#ifndef CPP_FILEOPENERROR_H
#define CPP_FILEOPENERROR_H
#include <exception>

class FileOpenError : public std::runtime_error {
public:
    explicit FileOpenError() : std::runtime_error("the file is not open"){};
};


#endif //CPP_FILEOPENERROR_H
