#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>


int main() {
    std::ifstream inputFile("input.txt");
    std::vector<int> firstNumbers;
    std::unordered_map<int, int> secondNumbers;

    int val1, val2;
    while (inputFile >> val1 >> val2) {
        firstNumbers.push_back(val1);
        secondNumbers[val2] += 1;
    }

    inputFile.close();

    int score = 0;


    for (const auto& num : firstNumbers) {
        score += num * secondNumbers[num];
    }

    std::cout << "The similarity score is: " << score << std::endl;


}