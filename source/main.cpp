#include <vector>
#include <iostream>

#include "../include/functions.hpp"


int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    std::cout << *Find(v.begin(), v.end(), 3) << std::endl;
    std::cout << *findInSorted(v.begin(), v.end(), -1) << std::endl;
    std::cout << wordsCounter("can     ypu can.gjrkfdls        u u") << std::endl;
}