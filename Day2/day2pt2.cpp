#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>

bool safePattern(int a, int b, bool isIncreasing)
{
    if (isIncreasing)
    {
        return a < b;
    }
    return a > b;
}

bool safeDifference(int a, int b, bool isIncreasing)
{
    if (!safePattern(a, b, isIncreasing))
    {
        return false;
    }
    int diff = a > b ? a - b : b - a;
    return (diff >= 1 && diff <= 3);
}

bool safeReport(std::list<int> &report, bool dampener)
{
    bool isIncreasing = false;
    bool dampened = false;
    auto it = report.begin();
    it++;
    while (it != report.end())
    {
        auto previousit = std::prev(it);
        auto nextit = std::next(it);
        int previousLevel = *previousit;
        int level = *it;

        if (previousit == report.begin())
        {
            isIncreasing = level > previousLevel;
        }

        if (!safeDifference(previousLevel, level, isIncreasing))
        {
            if (dampener && !dampened)
            {
                dampened = true;
                report.erase(previousit);

                if (safeReport(report, false))
                {
                    return true;
                }
                else
                {
                    report.insert(it, previousLevel);
                }

                it = report.erase(it);

                if (safeReport(report, false))
                {
                    return true;
                }
                else
                {
                    it = report.insert(it, level);
                }

                if (std::prev(it) != report.begin())
                {
                    auto previouspreviousit = std::prev(std::prev(it));
                    int previouspreviousLevel = *previouspreviousit;
                    report.erase(previouspreviousit);
                    if (safeReport(report, false))
                    {
                        return true;
                    }
                    else
                    {
                        report.insert(std::prev(it), previouspreviousLevel);
                    }
                }

                if (std::next(it) != report.end())
                {
                    int nextLevel = *std::next(it);
                    report.erase(nextit);
                    if (safeReport(report, false))
                    {
                        true;
                    }
                    else
                    {
                        report.insert(std::next(it), nextLevel);
                    }
                }
                else
                {
                    return true;
                }
            }
            return false;
        }
        it++;
    }
    return true;
}

void readReport(const char *filename, bool dampener)
{
    std::ifstream inputFile(filename);

    std::string line;

    int safeReports = 0;

    while (std::getline(inputFile, line))
    {
        int level;
        std::istringstream iss(line);
        std::list<int> report;
        std::list<int> origReport;
        while (iss >> level)
        {
            report.push_back(level);
            origReport.push_back(level);
        }
        if (safeReport(report, dampener))
        {
            safeReports++;
            std::cout << "The report is safe: ";
            for (const auto &level : origReport)
            {
                std::cout << level << " ";
            }
            std::cout << std::endl;
        }
        else
        {
            std::cout << "The report is not safe: ";
            for (const auto &level : origReport)
            {
                std::cout << level << " ";
            }
            std::cout << std::endl;
        }
    }
    inputFile.close();
    std::cout << "The number of safe reports is: " << safeReports << std::endl;
}

int testSafeReport()
{
    std::list<int> report1 = {7, 6, 4, 2, 1};
    std::list<int> report2 = {1, 2, 7, 8, 9};
    std::list<int> report3 = {9, 7, 6, 2, 1};
    std::list<int> report4 = {1, 3, 2, 4, 5};
    std::list<int> reportn = {1,4, 3,2, 1};
    std::list<int> report5 = {8, 6, 4, 4, 1};
    std::list<int> report6 = {1, 3, 6, 7, 9};
    std::list<int> report7 = {45, 47, 48, 51, 54, 56, 54};
    std::list<int> report8 = {76, 79, 81, 84, 84};
    std::list<int> report9 = {14, 13, 11, 9, 7, 4, 2};
    std::list<int> report10 = {61, 64, 67, 68, 67};
    std::list<int> report11 = {48,46, 47, 49, 51, 54, 56};

    bool rn = safeReport(reportn, true);
    bool r11 = safeReport(report11, true);

    std::cout << "Report n is safe: " << rn << std::endl;
    std::cout << "Report 11 is safe: " << r11 << std::endl;

    return 0;
}

int main()
{
    readReport("input.txt", true);
    //testSafeReport();
    //readReport("test.txt", true);
    return 0;
}
