#include "iostream"
#include <clocale>
#include <vector>
#include <utility>
#include "FileReader.h"
#include "SplitService.h"
#include "StatisticStorage.h"
#include "CSVFileWriter.h"

int main() {
    FileReader fileReader("input.txt");
    fileReader.open();
    SplitService splitter;
    StatisticStorage words;
    while (fileReader.hasNext()) {
        std::string str = fileReader.getNext();
        std::vector<std::string> splitStr = splitter.parse(str);
        for (const auto& word : splitStr) {
            words.addElement(word);
        }

    }
    fileReader.close();

    std::vector<std::pair<std::string, int>> data = words.getSortedStatistic();
    double total = words.getTotalNumber();
    CSVFileWriter fileWriter("output.csv");
    fileWriter.open();

    for (const auto& row : data) {
        std::vector<std::string> dataForLine;
        dataForLine.push_back(row.first);
        dataForLine.push_back(std::to_string(row.second));
        dataForLine.push_back(std::to_string(row.second / total));
        fileWriter.writeLine(dataForLine);
    }

    fileWriter.close();
    return 0;
}
