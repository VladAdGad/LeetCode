#include "vector"
#include "string"
#include "catch2/catch_all.hpp"

using namespace std;

string longestCommonPrefix(vector<string> &strings) {
    string prefix;
    int sizeOfStrings = strings.size();

    if (sizeOfStrings == 0) {
        return "";
    }
    if (sizeOfStrings == 1) {
        return strings[0];
    }

    prefix = strings[0];
    for (int i = 1; i < sizeOfStrings; ++i) {
        if (prefix.size() > strings[i].size()) {
            prefix = strings[i];
        }
    }

    for (int i = 0; i < sizeOfStrings; ++i) {
        string subStr = strings[i].substr(0, prefix.size());
        size_t match = subStr.find(prefix.c_str(), 0, prefix.size());
        if (match == string::npos) {
            string tmpPrefix = prefix;
            prefix = "";
            for (int count = 0; tmpPrefix[count] == strings[i].at(count); ++count) {
                prefix += tmpPrefix[count];
            }
            if (prefix.empty()) {
                return prefix;
            }
        }
    }

    return prefix;
}

TEST_CASE("AIOB") {
    REQUIRE(0 == 0);
}

//int main() {
//    vector<string> strings1 = {"flower", "flow", "flight"};
//    vector<string> strings2 = {"dog", "racecar", "car"};
//
//    string output1 = longestCommonPrefix(strings1);
//    string output2 = longestCommonPrefix(strings2);
//
//    printf("expect: fl\nprefix: %s\n", output1.c_str());
//    printf("expect: \nprefix: %s\n", output2.c_str());
//
//    return 0;
//}