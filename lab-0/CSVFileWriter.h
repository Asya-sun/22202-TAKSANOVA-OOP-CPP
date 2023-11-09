//
// Created by PC on 08.11.2023.
//

#ifndef LAB_0_CSVFILEWRITER_H
#define LAB_0_CSVFILEWRITER_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "FileOpenError.h"

class CSVFileWriter {
private:
    std::string filename;
    std::ofstream f;
    void checkPoint();
public:
    explicit CSVFileWriter(std::string fname) : filename(std::move(fname)) {
    }

    ~CSVFileWriter() {
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

    bool isOpen() {
        return f.is_open();
    }

    void writeLine(const std::vector<std::string>& words);
    void writeLine(const std::string &line);
};


#endif //LAB_0_CSVFILEWRITER_H
