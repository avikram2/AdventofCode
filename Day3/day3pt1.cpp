#include <iostream>
#include <fstream>
#include <regex>
#include <string>


int mul(const std::string &input)
{
    std::smatch matches;
    static const std::regex pattern(R"(mul\((\d+),(\d+)\))");

    int result = 0;

    std::string::const_iterator searchStart(input.cbegin());
    while (std::regex_search(searchStart, input.cend(), matches, pattern)) {
        std::cout << "Found: " << matches[0] << std::endl;
        result += std::stoi(matches[1]) * std::stoi(matches[2]);
        searchStart = matches.suffix().first;
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
    std::string input = "xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5)";
    int res = mul(input);
    std::cout << "The result is: " << res << std::endl;
}

int main()
{
    std::string input = readInput("input.txt");
    int res = mul(input);
    std::cout << "The result is: " << res << std::endl;

}