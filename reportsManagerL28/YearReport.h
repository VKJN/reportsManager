#pragma once
#include "Header.h"
#include "Report.h"
#include "MonthReport.h"

class YearReport : public Report {
    vector<MonthReport> monthReports;
    float resultYearSales = 0;
    float resultYearPurchases = 0;
public:
    YearReport(string path);
    void AddMonthReport(MonthReport monthReport);
    void showAllInfo();

    void matchChecking(vector<string> data, ReaderCsv reader);
};