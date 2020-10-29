#include "iostream"
#include "vector"
#include "../Utils/print.h"

using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {
    vector<int> output;

    if (matrix.empty()) {
        return {};
    }

    int row = matrix.size();
    if (row == 1) {
        return matrix[0];
    }

    int column = matrix[0].size();
    if (column == 1) {
        output.reserve(row * column);
        for (int i = 0; i < row; ++i) {
            output.push_back(matrix[i][0]);
        }

        return output;
    }

    int size = column * row;
    int i = 0;
    int j = 0;
    int count = 0;
    bool isUp = true;

    output.reserve(row * column);
    while (count != size) {

        if (isUp) {
            while (!(i == -1 || j == -1 || i == row || j == column)) {
                output.push_back(matrix[i--][j++]);
                count++;
            }
        } else {
            while (!(i == -1 || j == -1 || i == row || j == column)) {
                output.push_back(matrix[i++][j--]);
                count++;
            }
        }


        if (i == -1 && j != column) {
            i = 0;
        } else if (j >= column) {
            i += 2;
            j -= 1;
        }
        if (j == -1 && i != row) {
            j = 0;
        } else if (i >= row) {
            j += 2;
            i -= 1;
        }

        isUp = !isUp;
    }

    return output;
}

//int main() {
//    vector<vector<int>> matrix1{{1, 2, 3},
//                                {4, 5, 6},
//                                {7, 8, 9}};
//    vector<vector<int>> matrix2{{2, 3}};
//    vector<vector<int>> matrix3{{2},
//                                {3}};
//    vector<vector<int>> matrix4{};
//
//    vector<int> output1 = findDiagonalOrder(matrix1);
//    vector<int> output2 = findDiagonalOrder(matrix2);
//    vector<int> output3 = findDiagonalOrder(matrix3);
//    vector<int> output4 = findDiagonalOrder(matrix4);
//
//    printf("output: %s\nexpected: 1 2 4 7 5 3 6 8 9\n", print(output1).c_str());
//    printf("output: %s\nexpected: 2 3\n", print(output2).c_str());
//    printf("output: %s\nexpected: 2 3\n", print(output3).c_str());
//    printf("output: %s\nexpected: \n", print(output4).c_str());
//
//    return 0;
//}