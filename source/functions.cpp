#include <vector>
#include <iostream>
#include <algorithm>


std::vector<int>::iterator Find(std::vector<int>::iterator first, std::vector<int>::iterator last, int el) {
    for (std::vector<int>::iterator it = first; it != last; it++) {
        if (*it == el) return it;
    }
    return last;
}


std::vector<int>::iterator findInSorted(std::vector<int>::iterator first, std::vector<int>::iterator last, int el) {
    auto left = first;
    auto right = last;

    while (left <= right) {
        auto mid = left + (right - left) / 2;

        if (*mid == el) {
            return mid;
        } else if (*mid < el) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return last;
}


int wordsCounter(const std::string& str) {
    if (str.length() == 0) return 0;
    const std::string delimeters = " ,.";
    int delimeter_count = 0;
    for (int i = 1; i < str.length() - 1; i++) {
        if (
            (std::find(delimeters.begin(), delimeters.end(), str[i - 1]) == delimeters.end() ||
            std::find(delimeters.begin(), delimeters.end(), str[i + 1]) == delimeters.end()) &&
            std::find(delimeters.begin(), delimeters.end(), str[i]) != delimeters.end()
        ) delimeter_count += 1;
    }
    return delimeter_count + 1;
}