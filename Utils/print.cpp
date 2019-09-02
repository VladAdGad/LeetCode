#include <vector>
#include <iostream>

#include "print.h"

void print(const std::vector<int>& cont) {

    for (auto const& i : cont) {
        printf("{ %d } ", i);
    }
}

void print(const std::vector<std::vector<int>>& cont) {

    for (auto const& i : cont) {
        for(auto const& j : i) {
            printf("{ %d } ", j);
        }
    }
}
