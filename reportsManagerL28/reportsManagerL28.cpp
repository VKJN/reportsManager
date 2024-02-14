#include "Header.h"
#include "YearReport.h"

int main()
{
    ReaderCsv reader;

    MonthReport month1("m_1_2021.csv");
    MonthReport month2("m_2_2021.csv");
    MonthReport month3("m_3_2021.csv");

    YearReport year1("y_2021.csv");

    vector<string> data1 = reader.readFile("m_1_2021.csv");
    vector<string> data2 = reader.readFile("m_2_2021.csv");
    vector<string> data3 = reader.readFile("m_3_2021.csv");

    vector<string> dataYear = reader.readFile("y_2021.csv");

    month1.addMultTransactions(data1, reader, "m_1_2021.csv");
    month2.addMultTransactions(data2, reader, "m_2_2021.csv");
    month3.addMultTransactions(data3, reader, "m_3_2021.csv");

    year1.AddMonthReport(month1);
    year1.AddMonthReport(month2);
    year1.AddMonthReport(month3);

    year1.showAllInfo();

    year1.matchChecking(dataYear, reader);
}