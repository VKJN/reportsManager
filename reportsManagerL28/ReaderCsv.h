#pragma once
#include "Header.h"

class ReaderCsv {
public:
    vector<string> readFile(string path);
    vector<string> splitString(string tr, char splitter);
    string getFileName(string path);
    string getDate(string filename);
};