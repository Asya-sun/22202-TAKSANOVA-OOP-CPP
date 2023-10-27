//
// Created by PC on 19.10.2023.
//

#ifndef TASK_0_FILEREADER_H
#define TASK_0_FILEREADER_H

#include "string"
#include "iostream"
#include <fstream>


class FileReader {
private:
    std::string filename;
    std::ifstream f;
    void checkPoint() {
        if (!isOpen()) {
            throw "the file is not open";
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

#endif //TASK_0_FILEREADER_H
