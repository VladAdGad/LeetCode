#include <catch2/catch_all.hpp>
#include "singly_list_node.hpp"

bool hasCycle(SinglyListNode *head) {
    if (head == nullptr) {
        return false;
    }

    SinglyListNode *slow = head;
    SinglyListNode *fast = head->next;
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
        auto *listNode0 = new SinglyListNode(0);
        auto *listNode1 = new SinglyListNode(1);

        listNode0->next = listNode1;
        listNode1->next = listNode0;
        REQUIRE(hasCycle(listNode0) == true);
    }

    SECTION("linked list non-cycle") {
        auto *listNode0 = new SinglyListNode(1);
        auto *listNode1 = new SinglyListNode(2);

        listNode0->next = listNode1;
        REQUIRE(hasCycle(listNode0) == false);
    }

    SECTION("pass nullptr", "[Edge Case]") {
        REQUIRE(hasCycle(nullptr) == false);
    }

}
