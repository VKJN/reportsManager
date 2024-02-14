#include "Transaction.h"

Transaction::Transaction(string item, int price, bool type) {
	this->item = item;
	this->price = price;
	this->type = type;
}

string Transaction::getItem() {
	return item;
}

bool Transaction::getType() {
	return type;
}

int Transaction::getPrice() {
	return price;
}