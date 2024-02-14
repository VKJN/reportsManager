#pragma once
#include "Header.h"
#include "Report.h"
#include "Transaction.h"
#include "ReaderCsv.h"

class MonthReport : public Report {
private:
	vector<Transaction> transactions;
	float resultSales = 0;
	float resultPurchases = 0;
	string month;
public:
	MonthReport(string filePath);
	void AddTransaction(string item, int price, bool type);
	void addMultTransactions(vector<string> data, ReaderCsv reader, string path);

	float getSales();
	float getPurchases();
	string getMonth();

	void showAllInfo();
};