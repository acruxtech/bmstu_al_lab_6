#include <list>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <map>


const std::string delimeters = " ,.";



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
    int delimeter_count = 0; 
    bool is_word_now = std::find(delimeters.begin(), delimeters.end(), str[0]) == delimeters.end();
    for (int i = 1; i < str.length() - 1; i++) {
        if (is_word_now && !(std::find(delimeters.begin(), delimeters.end(), str[i]) == delimeters.end())) {
            delimeter_count += 1;
            is_word_now = false;
        }
        if (!is_word_now && (std::find(delimeters.begin(), delimeters.end(), str[i]) == delimeters.end())) {
            is_word_now = true;
        }
    }
    return delimeter_count + 1;
}


std::map<std::string, int> wordsMapCounter(const std::string& str) {
    std::map<std::string, int> res = {};
    if (str.size() == 0) return res;
    bool is_word_now = std::find(delimeters.begin(), delimeters.end(), str[0]) == delimeters.end();
    std::string word = "";
    if (is_word_now) word += str[0];
    for (int i = 1; i < str.length(); i++) {
        if (std::find(delimeters.begin(), delimeters.end(), str[i]) == delimeters.end()) {
            word += str[i];
        }
        if (
            is_word_now && (
                !(std::find(delimeters.begin(), delimeters.end(), str[i]) == delimeters.end()) ||
                i == str.length() - 1
            )
        ) {
            is_word_now = false;
            if (res.find(word) == res.end()) {
                res[word] = 1;
            }
            else {
                res[word] += 1;
            }
            word = "";
        }
        if (!is_word_now && (std::find(delimeters.begin(), delimeters.end(), str[i]) == delimeters.end())) {
            is_word_now = true;
        }
    }
    return res;
}


std::vector<std::string> uniqueWords(const std::string& str) {
    std::map<std::string, int> words_with_counts = wordsMapCounter(str);
    std::set<std::string> res;
    for (auto& pair : words_with_counts) {
        res.insert(pair.first);
    }
    return std::vector<std::string>(res.begin(), res.end());
}


int diffWordsCounter(const std::string& str) {
    std::vector<std::string> unique_words = uniqueWords(str);
    return unique_words.size();
}


void reverseNum(std::list<int>& numbers) {
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        numbers.insert(it, *it * -1);
    }
}


void plusesDeleter(std::vector<int>& numbers) {
    numbers.erase(
        std::remove_if(
            numbers.begin(), 
            numbers.end(), 
            [](int x) { return x > 0; }
        ),
        numbers.end()
    );
}


void Sort(std::vector<int>& numbers) {
    int t;
    for (int i = 0; i < numbers.size(); ++i) {
        for (int j = 0; j < numbers.size(); ++j) {
            if (numbers[i] > numbers[j]) {
                t = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = t;
            }
        }
    }
}
