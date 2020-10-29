#include "string"

using namespace std;

int strStr(string haystack, string needle) {
    int hSize = haystack.size();
    int nSize = needle.size();

    if (needle.empty()) {
        return 0;
    }

    if (nSize > hSize) {
        return -1;
    }

    for (int i = 0; i <= hSize - nSize; ++i) {
        if (haystack[i] == needle[0]) {
            int j = i + 1;
            int n = 1;
            while (j < hSize && haystack[j] == needle[n]) {
                j++;
                n++;
            }
            if (n == nSize) {
                return i;
            }
        }
    }

    return -1;
}

//int main() {
//    string haystack1 = "hello";
//    string needle1 = "ll";
//
//    printf("Expected: %d\n", 2);
//    printf("Actual: %d\n\n", strStr(haystack1, needle1));
//
//    string haystack2 = "aaaaa";
//    string needle2 = "bba";
//
//    printf("Expected: %d\n", -1);
//    printf("Actual: %d\n\n", strStr(haystack2, needle2));
//
//    string haystack3 = "mississippi";
//    string needle3 = "issip";
//
//    printf("Expected: %d\n", 4);
//    printf("Actual: %d\n\n", strStr(haystack3, needle3));
//
//    return 0;
//}