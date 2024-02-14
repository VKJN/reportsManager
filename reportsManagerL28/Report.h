#pragma once
#include "Header.h"

class Report {
private:
	string path;
public:
	Report(string filePath);
	virtual void showAllInfo() = 0;
};