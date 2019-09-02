#include "iostream"
#include "vector"
#include "../../Utils/print.h"

using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result(numRows);

    for (int i = 0; i < numRows; ++i) {
        result.at(i).resize(i + 1);
        result.at(i).at(0) = 1;
        result.at(i).at(i) = 1;
    }

    for (int i = 2; i < numRows; ++i) {
        for (int j = 1; j < i; ++j) {
            result.at(i).at(j) = result.at(i - 1).at(j - 1) + result.at(i - 1).at(j);
        }
    }

    return result;
}

int main() {
    vector<vector<int>> result1 = generate(5);
    
    printf("%s", print(result1).c_str());

    return 0;
}
