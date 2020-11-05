#include <catch2/catch_all.hpp>

class MinStack {
private:
    std::vector<int> values;
    std::vector<int> minValues;
    int indexOfMinNum = -1;
public:
    MinStack() = default;

    void push(int value) {
        if(values.empty()) {
            minValues.push_back(value);
        } else {
            minValues.push_back(std::min(minValues.back(), value));
        }
        values.push_back(value);
    }

    void pop() {
        values.pop_back();
        minValues.pop_back();
    }

    int top() {
        return values.back();
    }

    int getMin() {
        return minValues.back();
    }
};

TEST_CASE("Min Stack", "[Data Structures]") {
    MinStack *minStack;

    minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    REQUIRE(minStack->getMin() == -3);
    minStack->pop();
    REQUIRE(minStack->top() == 0);
    REQUIRE(minStack->getMin() == -2);

    minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-1);
    REQUIRE(minStack->getMin() == -2);
    REQUIRE(minStack->top() == -1);
    minStack->pop();
    REQUIRE(minStack->getMin() == -2);
}
