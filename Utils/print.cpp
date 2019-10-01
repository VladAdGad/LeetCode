#include <vector>
#include <string>
#include <iterator>
#include <sstream>

#include "print.h"

std::string print(const std::vector<int> &cont) {
    std::stringstream result;
    std::copy(cont.begin(), cont.end(), std::ostream_iterator<int>(result, " "));

    return result.str();
}

std::string print(const std::vector<char> &cont) {
    std::string result;

    for (char c : cont) {
        result.push_back(c);
        result.push_back(' ');
    }

    return result;
}

std::string print(const std::vector<std::vector<int>> &cont) {
    std::string result;
    std::string separator = " ";

    for (const auto &i: cont) {
        for (const auto j : i) {
            result += std::to_string(j) + separator;
        }
        result += "\n";
    }

    return result;
}
