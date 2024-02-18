#include "ReaderCsv.h"

vector<string> ReaderCsv::readFile(string path) {
    vector<string> lines;
    ifstream file(path);
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            lines.push_back(line);
        }
    }
    file.close();
    return lines;
}

string ReaderCsv::getFileName(string path) {
    reverse(path.begin(), path.end());

    string name;

    for (int i = 0; i < path.size(); i++) {
        if (path[i] != '\\') {
            name += path[i];
        }
        else {
            break;
        }
    }

    reverse(name.begin(), name.end());
    return name;
}

vector<string> ReaderCsv::splitString(string tr, char splitter) {
    vector<string> buf;
    string line;

    for (auto i : tr) {
        if (i == splitter) {
            buf.push_back(line);
            line.clear();
        }
        else {
            line += i;
        }
    }
    buf.push_back(line);

    return buf;
}

string ReaderCsv::getDate(string fileName) {

    string monthNumber;

    for (int i = 0; i < fileName.size(); i++) {
        if (fileName[i] == '_') {
            for (int j = i + 1; j < fileName.size(); j++) {
                if (fileName[j] != '_') {
                    monthNumber += fileName[j];
                }
                else {
                    i = fileName.size() - 1;
                    break;
                }
            }
        }
    }
    return monthNumber;
}
