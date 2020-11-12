#include <catch2/catch_all.hpp>
#include <stack>
#include <iostream>

bool isValid(const std::string& s) {
    std::stack<char> data;
    const std::map<char, char> parentheses = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
    };

    for (const char& elem : s) {
        if (elem == '(' || elem == '[' || elem == '{') {
            data.push(elem);
        } else {
            if (!data.empty()) {
                if (parentheses.find(data.top())->second == elem) {
                    data.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
    }

    return data.empty();
}

TEST_CASE("Valid Parentheses", "[Data Structures]") {
    REQUIRE(isValid("()") == true);
    REQUIRE(isValid("]") == false);
    REQUIRE(isValid("(])") == false);
    REQUIRE(isValid("()[]{}") == true);
    REQUIRE(isValid("(]") == false);
    REQUIRE(isValid("([)]") == false);
    REQUIRE(isValid("{[]}") == true);
}
