#pragma once
#include "Header.h"

class Transaction {
private:
	string item;
	int price = 0;
	bool type;
public:
	Transaction(string item, int price, bool type);

	string getItem();
	bool getType();
	int getPrice();
};