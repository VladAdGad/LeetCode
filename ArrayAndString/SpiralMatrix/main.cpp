#include "vector"
#include "iostream"
#include "../../Utils/print.cpp"

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> result;

    if (matrix.empty()) {
        return {};
    }

    int row = matrix.size();
    if (row == 1) {
        return matrix[0];
    }

    int column = matrix[0].size();
    if (column == 1) {
        result.reserve(row);
        for (int i = 0; i < row; ++i) {
            result.push_back(matrix[i][0]);
        }

        return result;
    }


    int size = row * column;
    int count = 0;
    int i = 0;
    int j = 0;
    int narrow = 0;

    result.reserve(size);
    while (count != size) {
        while (j != column - narrow) {
            result.push_back(matrix[i][j++]);
            count++;
        }
        j--;
        i++;
        if (count == size) {
            return result;
        }
        while (i < row - narrow) {
            result.push_back(matrix[i++][j]);
            count++;
        }
        i--;
        j--;
        if (count == size) {
            return result;
        }
        while (j >= narrow) {
            result.push_back(matrix[i][j--]);
            count++;
        }
        j++;
        i--;
        if (count == size) {
            return result;
        }
        narrow++;
        while (i >= narrow) {
            result.push_back(matrix[i--][j]);
            count++;
        }
        i++;
        j++;
    }

    return result;
}

int main() {
    vector<vector<int>> matrix1{{1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9}};
    vector<vector<int>> matrix2{{2, 3}};
    vector<vector<int>> matrix3{{2},
                                {3}};
    vector<vector<int>> matrix4{};

    vector<int> output1 = spiralOrder(matrix1);
    vector<int> output2 = spiralOrder(matrix2);
    vector<int> output3 = spiralOrder(matrix3);
    vector<int> output4 = spiralOrder(matrix4);

    print(output1);

//    printf("output: ");
//    for (const auto &elem : output1) {
//        printf("%d ", elem);
//    }
//    printf(" | expected: 1 2 3 6 9 8 7 4 5\n");
//
//    printf("output: ");
//    for (const auto &elem : output2) {
//        printf("%d ", elem);
//    }
//    printf(" | expected: 2 3\n");
//
//    printf("output: ");
//    for (const auto &elem : output3) {
//        printf("%d ", elem);
//    }
//    printf(" | expected: 2 3\n");
//
//    printf("output: ");
//    for (const auto &elem : output4) {
//        printf("%d ", elem);
//    }
//    printf(" | expected: {}\n");

    return 0;
}