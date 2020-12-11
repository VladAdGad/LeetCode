#include <catch2/catch_all.hpp>

void xorSwap (char& n1, char& n2) {
    n1 ^= n2;
    n2 ^= n1;
    n1 ^= n2;
}

std::vector<char> reverseString(std::vector<char> &s) {

    for (int pointer1 = 0, pointer2 = s.size() - 1; pointer1 < pointer2; ++pointer1, --pointer2) {
        xorSwap(s[pointer1], s[pointer2]);
    }

    return s;
}

TEST_CASE("Reverse String", "[Data Structures]") {
    std::vector<char> vector;

    vector = {};
    REQUIRE_THAT(reverseString(vector), Catch::Matchers::Equals(std::vector<char>{}));

    vector = {'h'};
    REQUIRE_THAT(reverseString(vector), Catch::Matchers::Equals(std::vector<char>{'h'}));

    vector = {'h', 'e', 'l', 'l', 'o'};
    REQUIRE_THAT(reverseString(vector), Catch::Matchers::Equals(std::vector<char>{'o', 'l', 'l', 'e', 'h'}));

    vector = {'H', 'a', 'n', 'n', 'a', 'h'};
    REQUIRE_THAT(reverseString(vector), Catch::Matchers::Equals(std::vector<char>{'h', 'a', 'n', 'n', 'a', 'H'}));
}
