//
// Created by PC on 21.10.2023.
//
#include <string>
#include <iostream>
#include <fstream>
#include "../CSVFileWriter.h"

void CSVFileWriter::writeLine(const std::vector<std::string> &words) {
    std::string line;
    for (const auto &word: words) {
        line += word + ";";
    }
    CSVFileWriter::writeLine(line);
}

void CSVFileWriter::writeLine(const std::string &line) {
    f << line << "\n";
}

void CSVFileWriter::checkPoint() {

    if (!isOpen()) {
        throw FileOpenError();
    }
}
