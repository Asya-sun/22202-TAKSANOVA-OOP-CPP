//
// Created by PC on 21.10.2023.
//

#ifndef TASK_0_CSVFILEWRITER_H
#define TASK_0_CSVFILEWRITER_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>


class CSVFileWriter {
private:
    std::string filename;
    std::ofstream f;
    void checkPoint() {
        if (!isOpen()) {
            throw "the file is not open";
        }
    }
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


#endif //TASK_0_CSVFILEWRITER_H
