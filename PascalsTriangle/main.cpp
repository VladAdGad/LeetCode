#include "iostream"
#include "vector"

using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;
    result.resize(numRows);

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

    for (int k = 0; k < result1.size(); ++k) {
        for (int l = 0; l < result1[k].size(); ++l) {
            cout << result1[k][l] << ' ';
        }

        cout << endl;
    }

    return 0;
}
