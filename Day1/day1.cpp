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


    for (auto it = firstNumbers.begin(); it != firstNumbers.end(); ++it) {
        // get the same iterator in the second set
        auto it2 = (it - firstNumbers.begin()) + secondNumbers.begin();
        int L1 = (*it > *it2) ? (*it -*it2) : (*it2 - *it);
        difference += L1;
    }

    std::cout << "The sum of the differences is: " << difference << std::endl;


}