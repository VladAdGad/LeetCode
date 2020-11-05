#include <catch2/catch_all.hpp>

class MinStack {
private:
    std::vector<int> data;
    int indexOfMinNum = -1;
public:
    /** initialize your data structure here. */
    MinStack() = default;

    void push(int value) {
        if (data.empty()) {
            indexOfMinNum = 0;
        }

        data.push_back(value);

        if (getMin() > value) {
            indexOfMinNum = data.size() - 1;
        }
    }

    void pop() {
        if (data.size() - 1 == indexOfMinNum) {
            data.pop_back();
            indexOfMinNum = 0;
            for (int i = 0; i < data.size(); ++i) {
                if (getMin() > data[i]) {
                    indexOfMinNum = i;
                }
            }
        } else {
            data.pop_back();
        }
    }

    int top() {
        return data.back();
    }

    int getMin() {
        return data[indexOfMinNum];
    }
};

TEST_CASE("Min Stack", "[Data Structures]") {
    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    minStack->getMin(); // return -3
    minStack->pop();
    minStack->top();    // return 0
    minStack->getMin(); // return -2
}
