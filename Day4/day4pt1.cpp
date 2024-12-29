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

int checkDiagonal(const std::string &input, const int line_length, const int x_position)
{
    // inc
    auto diagonal1 = x_position + line_length + 1;
    auto diagonal2 = x_position + line_length - 1;

    // dec
    auto diagonal3 = x_position - line_length + 1;
    auto diagonal4 = x_position - line_length - 1;

    int matches = 0;

    if (diagonal1 < input.length() && (x_position + 1) % line_length != 0)
    {
        if (input[diagonal1] == 'M')
        {
            if (diagonal1 + line_length + 1 < input.length() && (diagonal1+ 1) % line_length != 0)
            {
                if (input[diagonal1 + line_length + 1] == 'A')
                {
                    if (diagonal1 + line_length * 2 + 2 < input.length() && (diagonal1 + line_length + 1 + 1 ) % line_length != 0)
                    {
                        if (input[diagonal1 + line_length * 2 + 2] == 'S')
                        {
                            ++matches;
                            std::cout << "Found diagonal match at position: " << x_position << std::endl;
                        }
                    }
                }
            }
        }
    }

    if (diagonal2 < input.length() && diagonal2 >= 0 &&( (x_position) % line_length != 0))
    {
        if (input[diagonal2] == 'M')
        {
            if (diagonal2 + line_length - 1 < input.length() && (diagonal2 + line_length - 1 >= 0) && (diagonal2) % line_length != 0)
            {
                if (input[diagonal2 + line_length - 1] == 'A')
                {
                    if ((diagonal2 + line_length * 2 - 2 < input.length()) && (diagonal2 + line_length * 2 - 2 >= 0) && (diagonal2 + line_length - 1) % line_length != 0)
                    {
                        if (input[diagonal2 + line_length * 2 - 2] == 'S')
                        {
                            ++matches;
                            std::cout << "Found diagonal match at position: " << x_position << std::endl;
                        }
                    }
                }
            }
        }
    }

    if (diagonal3 < input.length() && diagonal3 >= 0 && (x_position + 1) % line_length != 0)
    {
        if (input[diagonal3] == 'M')
        {
            if (diagonal3 - line_length + 1 < input.length() && diagonal3 - line_length + 1 >= 0 && ((diagonal3+1) % line_length != 0))
            {
                if (input[diagonal3 - line_length + 1] == 'A')
                {
                    if (diagonal3 - line_length * 2 + 2 < input.length() && (diagonal3 - line_length * 2 + 2 >= 0) && (diagonal3 - line_length + 2) % line_length != 0)
                    {
                        if (input[diagonal3 - line_length * 2 + 2] == 'S')
                        {
                            ++matches;
                            std::cout << "Found diagonal match at position: " << x_position << std::endl;
                        }
                    }
                }
            }
        }
    }

    if (diagonal4 < input.length() && diagonal4 >= 0 && ((x_position) % line_length != 0))
    {
        if (input[diagonal4] == 'M')
        {
            if ((diagonal4 - line_length - 1 < input.length()) && (diagonal4 - line_length - 1 >= 0) && ((diagonal4) % line_length != 0))
            {
                if (input[diagonal4 - line_length - 1] == 'A')
                {
                    if ((diagonal4 - line_length * 2 - 2) < input.length() && (diagonal4 - line_length * 2 - 2 >= 0) && (diagonal4 - line_length - 1) % line_length != 0)
                    {
                        if (input[diagonal4 - line_length * 2 - 2] == 'S')
                        {
                            ++matches;
                            std::cout << "Found diagonal match at position: " << x_position << std::endl;
                        }
                    }
                }
            }
        }
    }

    return matches;
}

int checkHorizontal(const std::string &input, const int line_length, const int x_position)
{
    int matches = 0;
    // inc
    auto horizontal1 = x_position + 1;

    // dec
    auto horizontal3 = x_position - 1;

    if (horizontal1 < input.length() && ((x_position + 1) % line_length != 0))
    {
        if (input[horizontal1] == 'M')
        {
            if ((horizontal1 + 1) < input.length() && ((horizontal1 + 1) % line_length != 0))
            {
                if (input[horizontal1 + 1] == 'A')
                {
                    if ((horizontal1 + 2) < input.length() && ((horizontal1 + 2) % line_length != 0))
                    {
                        if (input[horizontal1 + 2] == 'S')
                        {
                            ++matches;
                            std::cout << "Found horizontal match at position: " << x_position << std::endl;
                        }
                    }
                }
            }
        }
    }

    if (horizontal3 < input.length() && horizontal3 >= 0 && (x_position % line_length != 0))
    {
        if (input[horizontal3] == 'M')
        {
            if ((horizontal3 - 1) < input.length() && (horizontal3 - 1 >= 0) && ((horizontal3) % line_length != 0))
            {
                if (input[horizontal3 - 1] == 'A')
                {
                    if ((horizontal3 - 2) < input.length() && (horizontal3 - 2 >= 0) && ((horizontal3 - 1) % line_length != 0))
                    {
                        if (input[horizontal3 - 2] == 'S')
                        {
                            ++matches;
                            std::cout << "Found horizontal match at position: " << x_position << std::endl;
                        }
                    }
                }
            }
        }
    }

    return matches;
}

int checkVertical(const std::string &input, const int line_length, const int x_position)
{
    int matches = 0;
    // inc
    auto vertical1 = x_position + line_length;

    // dec
    auto vertical3 = x_position - line_length;

    if (vertical1 < input.length())
    {
        if (input[vertical1] == 'M')
        {
            if (vertical1 + line_length < input.length())
            {
                if (input[vertical1 + line_length] == 'A')
                {
                    if (vertical1 + line_length * 2 < input.length())
                    {
                        if (input[vertical1 + line_length * 2] == 'S')
                        {
                            ++matches;
                            std::cout << "Found vertical match at position: " << x_position << std::endl;
                        }
                    }
                }
            }
        }
    }

    if (vertical3 < input.length() && vertical3 >= 0)
    {
        if (input[vertical3] == 'M')
        {
            if (vertical3 - line_length < input.length() && vertical3 - line_length >= 0)
            {
                if (input[vertical3 - line_length] == 'A')
                {
                    if (vertical3 - line_length * 2 < input.length() && (vertical3 - line_length * 2 >= 0))
                    {
                        if (input[vertical3 - line_length * 2] == 'S')
                        {
                            ++matches;
                            std::cout << "Found vertical match at position: " << x_position << std::endl;
                        }
                    }
                }
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
        if (input[i] == 'X')
        {
            int horizontalMatches = checkHorizontal(input, line_length, i);
            int verticalMatches = checkVertical(input, line_length, i);
            int diagonalMatches = checkDiagonal(input, line_length, i);
            numMatches += horizontalMatches + verticalMatches + diagonalMatches;
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
    processInput("test2.txt", input, line_length);
    findXMAS(input, line_length);
    return 0;

}

int main()
{
    run();
    //test_txt();
    return 0;
}