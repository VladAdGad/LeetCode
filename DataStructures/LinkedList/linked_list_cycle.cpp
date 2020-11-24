#include <catch2/catch_all.hpp>

class ListNode {
public:
    int value;
    ListNode *next;

    explicit ListNode(int value) {
        this->value = value;
        next = nullptr;
    }
};

bool hasCycle(ListNode *head) {
    if (head == nullptr) {
        return false;
    }

    ListNode *slow = head;
    ListNode *fast = head->next;
    while (slow != fast) {
        if (fast == nullptr || fast->next == nullptr) {
            return false;
        }

        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}

TEST_CASE("Linked List Cycle", "[Data Structures]") {

    SECTION("linked list cycle") {
        auto *listNode0 = new ListNode(0);
        auto *listNode1 = new ListNode(1);

        listNode0->next = listNode1;
        listNode1->next = listNode0;
        REQUIRE(hasCycle(listNode0) == true);
    }

    SECTION("linked list non-cycle") {
        auto *listNode0 = new ListNode(1);
        auto *listNode1 = new ListNode(2);

        listNode0->next = listNode1;
        REQUIRE(hasCycle(listNode0) == false);
    }

    SECTION("pass nullptr", "[Edge Case]") {
        REQUIRE(hasCycle(nullptr) == false);
    }

}
