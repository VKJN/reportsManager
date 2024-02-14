#include "YearReport.h"

YearReport::YearReport(string path) : Report(path) {}

void YearReport::AddMonthReport(MonthReport monthReport) {
	monthReports.push_back(monthReport);
	resultYearPurchases += monthReport.getPurchases();
	resultYearSales += monthReport.getSales();
}

void YearReport::showAllInfo() {
	cout << "Year report: " << "\n\n";

	for (auto i : monthReports) {
		i.showAllInfo();
	}

	cout << "Year sales: " << resultYearSales << endl << "Year purchases: " << resultYearPurchases << endl;
}

void YearReport::matchChecking(vector<string> data, ReaderCsv reader) {
	int count = 0;
	for (auto monthTr : data) {
		vector<string> monthTransactionParts = reader.splitString(monthTr, ';');
		if (monthReports.size() == monthTransactionParts.size()) {
			for (auto month : monthReports) {
				if (month.getMonth() == monthTransactionParts[0] && month.getSales() == stoi(monthTransactionParts[1]) &&
					month.getPurchases() == stoi(monthTransactionParts[2])) {
					count++;
				}
			}
		}
		else {
			cout << "The number of monthly reports don't match the number of months in the year report" << endl;
		}
	}
	if (count == monthReports.size()) {
		cout << "All data matches" << endl;
	}
	else {
		cout << "Not all data matches" << endl;
	}
}