#include <iostream>
#include <vector>
#include "../../Utils/print.h"

using namespace std;

vector<char> reverseString(vector<char> &s) {
    vector<char> output;
    int size = s.size();

    for (int i = 0; i < size / 2; ++i) {
        swap(s[i], s[size - i - 1]);
    }

    return s;
}

int main() {
    vector<char> input1 = {'h', 'e', 'l', 'l', 'o'};

    vector<char> output1 = reverseString(input1);

    printf("output: %s\nexpected: o l l e h", print(output1).c_str());

    return 0;
}
