#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void processInput(const char *filename, std::string &input, int &line_length)
{
    std::ifstream inputFile(filename);

    std::string line;

    while (std::getline(inputFile, line))
    {
        line_length = line.length();
        input += line;
    }

    inputFile.close();
}

int checkXMAS(const std::string &input, const int line_length, const int a_position)
{
    int matches = 0;

    // inc
    auto diagonal1 = a_position + line_length + 1;
    auto diagonal2 = a_position + line_length - 1;

    // dec
    auto diagonal3 = a_position - line_length + 1;
    auto diagonal4 = a_position - line_length - 1;

    if (a_position == 75)
    {
        std::cout << "Found A at position: " << a_position << std::endl;
    }

    if (a_position > line_length && (a_position < (input.length() - line_length)) && ((a_position + 1) % line_length != 0) && (a_position % line_length != 0))
    {

        if (a_position == 75)
        {
            std::cout << "Checking diagonals: " << diagonal1 << " " << diagonal2 << " " << diagonal3 << " " << diagonal4 << std::endl;
        }

        if (((input[diagonal1] == 'M') && (input[diagonal4] == 'S')) || ((input[diagonal1] == 'S') && (input[diagonal4] == 'M')))
        {
            if (((input[diagonal2] == 'M') && (input[diagonal3] == 'S')) || ((input[diagonal2] == 'S') && (input[diagonal3] == 'M')))
            {
                ++matches;
                std::cout << "Found XMAS match at position: " << a_position << std::endl;
            }
        }
    }

    return matches;
}

void findXMAS(const std::string &input, const int line_length)
{
    int numMatches = 0;
    for (int i = 0; i < input.length(); i++)
    {
        if (i == 75)
        {
            std::cout << "Checking position: " << i << input[i] << std::endl;
        }
        if (input[i] == 'A')
        {
            int matches = checkXMAS(input, line_length, i);
            numMatches += matches;
        }
    }
    std::cout << "The number of XMAS matches is: " << numMatches << std::endl;
}

int run()
{
    std::string input;
    int line_length;
    processInput("input.txt", input, line_length);
    findXMAS(input, line_length);
    return 0;
}

int test_txt()
{
    std::string input;
    int line_length;
    processInput("test.txt", input, line_length);
    findXMAS(input, line_length);
    return 0;

}

int main()
{
    run();
    //test_txt();
    return 0;
}