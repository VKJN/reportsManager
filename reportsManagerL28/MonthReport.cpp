#include "MonthReport.h"

MonthReport::MonthReport(string filePath) : Report(filePath) {}

void MonthReport::AddTransaction(string item, int price, bool type) {
    transactions.push_back(Transaction(item, price, type));
    if (type == true) resultSales += price;
    else resultPurchases += price;
}

float MonthReport::getSales() {
    return resultSales;
}

float MonthReport::getPurchases() {
    return resultPurchases;
}

string MonthReport::getMonth() {
    return month;
}

void MonthReport::showAllInfo() {
    int countTransactions = 1;

    cout << "Month - " << month << endl << "Transactions: " << endl;

    for (auto i : transactions) {
        cout << "Transaction number - " << countTransactions++ << ":" << endl;
        cout << "Item: " << i.getItem() << " | " << "Price: " << i.getPrice() << " | " << "Type: " << (i.getType() == true ? "Sales" : "Purchases") << "\n\n";
    }

    cout << "Sales: " << resultSales << endl << "Purchases: " << resultPurchases << "\n\n\n\n";
}

void MonthReport::addMultTransactions(vector<string> data, ReaderCsv reader, string path) {
    for (auto tr : data) {
        vector<string> transactionParts = reader.splitString(tr, ';');
        AddTransaction(transactionParts[0], stof(transactionParts[1]), (transactionParts[2] == "true" ? true : false));
    }

    int monthNumber = stoi(reader.getDate(reader.getFileName(path)));
    switch (monthNumber) {
    case 1:
        month = "January";
        break;
    case 2:
        month = "February";
        break;
    case 3:
        month = "March";
        break;
    case 4:
        month = "April";
        break;
    case 5:
        month = "May";
        break;
    case 6:
        month = "June";
        break;
    case 7:
        month = "July";
        break;
    case 8:
        month = "August";
        break;
    case 9:
        month = "September";
        break;
    case 10:
        month = "October";
        break;
    case 11:
        month = "November";
        break;
    case 12:
        month = "December";
        break;
    }
}