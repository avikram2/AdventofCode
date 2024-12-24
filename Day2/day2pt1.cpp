#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

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

void readReport(const char* filename)
{
    std::ifstream inputFile(filename);

    std::string line;

    int safeReports = 0;

    while (std::getline(inputFile, line))
    {
        int levelIndex = 0;
        int previousLevel = 0;
        bool isIncreasing = false;
        bool isSafe = true;
        std::istringstream iss(line);
        int level;
        while (iss >> level)
        {

            if (levelIndex == 0)
            {
                previousLevel = level;
                levelIndex++;
                continue;
            }

            else if (levelIndex == 1)
            {
                isIncreasing = level > previousLevel;
            }

            if (!safeDifference(previousLevel, level, isIncreasing))
            {
                isSafe = false;
                break;
            }

            previousLevel = level;
            levelIndex++;
        }
        if (isSafe)
        {
            safeReports++;
        }
    }
    inputFile.close();
    std::cout << "The number of safe reports is: " << safeReports << std::endl;
}

int main()
{
    readReport("input.txt");
    return 0;
}