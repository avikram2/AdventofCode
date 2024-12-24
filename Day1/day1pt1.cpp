#include <iostream>
#include <fstream>
#include <set>


int main() {
    std::ifstream inputFile("input.txt");
    std::multiset<int> firstNumbers;
    std::multiset<int> secondNumbers;

    int val1, val2;
    while (inputFile >> val1 >> val2) {
        firstNumbers.insert(val1);
        secondNumbers.insert(val2);
    }

    inputFile.close();

    int difference = 0;


    auto it = firstNumbers.begin();
    auto it2 = secondNumbers.begin();

    while (it != firstNumbers.end() && it2 != secondNumbers.end()) {
        int absSum = (*it > *it2) ? (*it - *it2) : (*it2 - *it);
        difference += absSum;
        it++;
        it2++;
    } 

    std::cout << "The sum of the differences is: " << difference << std::endl;


}