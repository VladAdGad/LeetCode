#include <catch2/catch_all.hpp>
#include "list_node.h"

ListNode *detectCycle(ListNode *head) {
    ListNode *walker = head, *runner = head;

    while (runner != nullptr && runner->next != nullptr) {
        runner = runner->next->next;
        walker = walker->next;

        if (runner == walker) {
            ListNode *seeker = head;

            while (seeker != walker) {
                walker = walker->next;
                seeker = seeker->next;
            }

            return walker;
        }
    }

    return runner;
}

TEST_CASE("Linked List Cycle II", "[Data Structures]") {

    SECTION("linked list cycle") {
        auto *listNode0 = new ListNode(3);
        auto *listNode1 = new ListNode(2);
        auto *listNode2 = new ListNode(0);
        auto *listNode3 = new ListNode(-4);

        listNode0->next = listNode1;
        listNode1->next = listNode2;
        listNode2->next = listNode3;
        listNode3->next = listNode1;
        REQUIRE(detectCycle(listNode0) == listNode1);
    }

    SECTION("linked list non-cycle") {
        auto *listNode0 = new ListNode(1);
        auto *listNode1 = new ListNode(2);

        listNode0->next = listNode1;
        REQUIRE(detectCycle(listNode0) == nullptr);
    }

    SECTION("pass nullptr", "[Edge Case]") {
        REQUIRE(detectCycle(nullptr) == nullptr);
    }

}
