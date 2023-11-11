//
// Created by PC on 08.11.2023.
//

#ifndef LAB_0_FILEREADER_H
#define LAB_0_FILEREADER_H

#include "string"
#include "iostream"
#include <fstream>
#include "FileOpenError.h"

class FileReader {
private:
    std::string filename;
    std::ifstream f;
    void checkPoint() {
        if (!isOpen()) {
            throw FileOpenError();
        }
    }
public:
    explicit FileReader(std::string fname) : filename(std::move(fname)) {
    }

    ~FileReader() {
        if (isOpen()) {
            f.close();
        }
    };


    void open() {
        f.open(filename);
    }

    void close() {
        checkPoint();
        f.close();
    }

    // вернуть в начало
    void reset() {
        checkPoint();
        f.clear();
        f.seekg(0);
    }

    bool isOpen()  {
        return f.is_open();
    }

    // есть ли еще данные для считывания
    bool hasNext() {
        checkPoint();
        return f.peek() != EOF;
    }

    // дай след. строчку
    // can return error
    std::string getNext() {
        checkPoint();
        std::string new_line;
        getline(f, new_line);
        return new_line;
    }
};

#endif //LAB_0_FILEREADER_H
