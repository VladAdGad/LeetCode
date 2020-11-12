#include <catch2/catch_all.hpp>
#include <stack>

std::vector<int> dailyTemperatures1(std::vector<int>& dailyTemperatures) {
    std::vector<int> daysToWait(dailyTemperatures.size(), 0);

    for (int i = 0; i < dailyTemperatures.size(); ++i) {
        for (int j = i + 1; j < dailyTemperatures.size(); ++j) {
            if (dailyTemperatures[i] < dailyTemperatures[j]) {
                daysToWait[i] = j - i;
                break;
            }
        }
    }

    return daysToWait;
}

std::vector<int> dailyTemperatures2(std::vector<int>& temperatures) {
    std::vector<int> result(temperatures.size(), 0);
    std::stack<std::pair<int, int>> s; //First is the number while second is the position

    for (int i = temperatures.size() - 1; i >= 0; i--) {
        int curr = temperatures[i];
        while (!s.empty() && s.top().first <= curr) {
            s.pop();
        }

        result[i] = s.empty() ? 0 : s.top().second - i;

        s.push({curr, i});
    }

    return result;
}

TEST_CASE("Daily Temperatures", "[Data Structures]") {
    std::vector<int> dailyTemperatures;

    dailyTemperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    REQUIRE_THAT(dailyTemperatures2(dailyTemperatures), Catch::Matchers::Equals(std::vector<int>{1, 1, 4, 2, 1, 1, 0, 0}));
}
