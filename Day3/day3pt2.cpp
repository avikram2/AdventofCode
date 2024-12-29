#include <iostream>
#include <fstream>
#include <regex>
#include <string>

int mul(const std::string &input)
{
    std::smatch matches1;
    std::smatch matches2;
    std::smatch matches3;
    static const std::regex pattern(R"(mul\((\d+),(\d+)\))");
    static const std::regex disable_multiplication(R"(don't\(\))");
    static const std::regex enable_multiplication(R"(do\(\))");

    int result = 0;
    size_t pos = 0;

    bool disable = false;
    while (pos < input.size())
    {
        size_t patternStart = std::string::npos;
        size_t disableStart = std::string::npos;
        size_t enableStart = std::string::npos;

        bool foundPattern = std::regex_search(input.begin() + pos, input.end(), matches1, pattern);
        bool foundDisable = std::regex_search(input.begin() + pos, input.end(), matches2, disable_multiplication);
        bool foundEnable = std::regex_search(input.begin() + pos, input.end(), matches3, enable_multiplication);

        if (foundPattern) {
            patternStart = matches1.position(0) + pos;
        }
        if (foundDisable) {
            disableStart = matches2.position(0) + pos;
        }
        if (foundEnable) {
            enableStart = matches3.position(0) + pos;
        }

        if (foundPattern && (patternStart < disableStart && patternStart < enableStart))
        {
            if (!disable)
                result += std::stoi(matches1[1]) * std::stoi(matches1[2]);
            pos = patternStart + matches1.length(0);
        }
        else if (foundDisable && (disableStart < patternStart && disableStart < enableStart))
        {
            disable = true;
            pos = disableStart + matches2.length(0);
        }
        else if (foundEnable && (enableStart < patternStart && enableStart < disableStart))
        {
            disable = false;
            pos = enableStart + matches3.length(0);
        }
        else
        {
            pos++;
        }
    }

    return result;
}

std::string readInput(const char *filename)
{
    std::ifstream inputFile(filename);
    std::string input;
    std::string line;
    while (std::getline(inputFile, line))
    {
        input += line;
    }
    inputFile.close();
    return input;
}

void testSearchForMul()
{
    std::string input;
    int res;
    input = "xmul(2,4)&mul[3,7]!^don't()_mul(5,5)+mul(32,64](mul(11,8)undo()?mul(8,5))";
    res = mul(input);
    std::cout << "The result is: " << res << std::endl;
}

void run()
{
    std::string input = readInput("input.txt");
    int res = mul(input);
    std::cout << "The result is: " << res << std::endl;
}

int main()
{
    run();
    return 0;
}