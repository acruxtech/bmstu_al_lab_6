#include <vector>
#include <iostream>
#include <list>

#include "../include/functions.hpp"


int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};

    std::cout << *Find(v.begin(), v.end(), 3) << std::endl;

    std::cout << *findInSorted(v.begin(), v.end(), -1) << std::endl;

    std::cout << wordsCounter("can     ypu can.gjrkfdls  rew ewe      uuu") << std::endl;

    for (auto& pair : wordsMapCounter("can     ypu can.gjrkfdls  rew ewe      uuu")) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    for (auto& item : uniqueWords("can     ypu can.gjrkfdls  rew ewe      u u")) {
        std::cout << item << " ";
    }
    std::cout << "\n";

    std::cout << diffWordsCounter("can     ypu can.gjrkfdls  rew ewe      u u") << std::endl;

    std::list<int> nums1 = {1, 5, 4, -3};
    reverseNum(nums1);
    for (auto& item : nums1) {
        std::cout << item << " ";
    }
    std::cout << "\n";

    std::list<int> nums2 = {1, 5, 4, -3};
    reverseNum(nums2);
    for (auto& item : nums2) {
        std::cout << item << " ";
    }
    std::cout << "\n";

    std::vector<int> nums3 = {1, 0, -8, -9, 0, 10, 23, -7};
    plusesDeleter(nums3);
    for (auto& item : nums3) {
        std::cout << item << " ";
    }
    std::cout << "\n";

    std::vector<int> nums4 = {1, 5, 4, -3};
    Sort(nums4);
    for (auto& item : nums4) {
        std::cout << item << " ";
    }
    std::cout << "\n";

    return 0;
}