#include <catch2/catch_all.hpp>
#include "list_node.hpp"

class SinglyLinkedList {
public:
    ListNode *head;
    ListNode *tail;
    int size = 0;

    SinglyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    [[nodiscard]] int get(int index) const {
        if (index >= size) {
            return -1;
        }

        int count = 0;
        for (ListNode *cur = head; count != index + 1; cur = cur->next, ++count) {
            if (count == index) {
                return cur->value;
            }
        }

        return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    bool addAtHead(int val) {
        auto *newNode = new ListNode(val);

        newNode->next = head;
        head = newNode;

        if (size == 0) {
            tail = head;
        }
        size++;
        return true;
    }

    /** Append a node of value val to the last element of the linked list. */
    bool addAtTail(int val) {
        auto *newNode = new ListNode(val);

        if (size == 0) {
            tail = newNode;
            head = tail;
            size++;
            return true;
        }

        tail->next = newNode;
        tail = newNode;
        size++;
        return true;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    bool addAtIndex(int index, int val) {
        if (index > size) {
            return false;
        }

        if (index == size) {
            return addAtTail(val);
        }

        if (size == 0 || index == 0) {
            return addAtHead(val);
        }

        int count = 0;
        for (ListNode *cur = head; count != index + 1; cur = cur->next, ++count) {
            if (count == index - 1) {
                auto *newNode = new ListNode(val);
                newNode->next = cur->next;
                cur->next = newNode;
                size++;
                return true;
            }
        }

        return false;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    bool deleteAtIndex(int index) {
        if (index >= size) {
            return false;
        }

        if (index == 0) {
            head = head->next;
            size--;
            return true;
        }

        int count = 0;
        for (ListNode *cur = head; count != index + 1; cur = cur->next, ++count) {
            if (count == index - 1) {
                cur->next = cur->next->next;
                if (index == size - 1) {
                    tail = cur;
                }
                size--;
                return true;
            }
        }

        return false;
    }
};

TEST_CASE("Linked List", "[Data Structures]") {

    SinglyLinkedList *linkedList;

    SECTION("get using empty linked list") {
        linkedList = new SinglyLinkedList();
        REQUIRE(linkedList->get(0) == -1);
    }

    SECTION("get using index which is higher than size of linked list") {
        linkedList = new SinglyLinkedList();
        linkedList->addAtHead(0);
        REQUIRE(linkedList->get(1) == -1);
    }

    SECTION("addAtHead with empty linked list") {
        linkedList = new SinglyLinkedList();
        linkedList->addAtHead(0);
        REQUIRE(linkedList->get(0) == 0);
        REQUIRE(linkedList->head == linkedList->tail);
    }

    SECTION("addAtHead multiple times") {
        linkedList = new SinglyLinkedList();
        linkedList->addAtHead(0);
        linkedList->addAtHead(1);
        REQUIRE(linkedList->head != linkedList->tail);
        REQUIRE(linkedList->get(0) == 1);
        REQUIRE(linkedList->get(1) == 0);
        REQUIRE(linkedList->head->value == 1);
        REQUIRE(linkedList->tail->value == 0);
    }

    SECTION("addAtTail multiple times") {
        linkedList = new SinglyLinkedList();
        linkedList->addAtTail(0);
        linkedList->addAtTail(1);
        REQUIRE(linkedList->head != linkedList->tail);
        REQUIRE(linkedList->get(0) == 0);
        REQUIRE(linkedList->get(1) == 1);
        REQUIRE(linkedList->tail->value == 1);
        REQUIRE(linkedList->head->value == 0);
    }

    SECTION("addAtTail with empty linked list") {
        linkedList = new SinglyLinkedList();
        linkedList->addAtHead(0);
        REQUIRE(linkedList->get(0) == 0);
        REQUIRE(linkedList->tail == linkedList->head);
    }

    SECTION("addAtIndex using index which is higher than size of linked list") {
        linkedList = new SinglyLinkedList();
        linkedList->addAtHead(0);
        REQUIRE(linkedList->addAtIndex(2, 1) == false);
    }

    SECTION("addAtIndex using index zero (first element) with empty linked list") {
        linkedList = new SinglyLinkedList();
        REQUIRE(linkedList->addAtIndex(0, 0) == true);
        REQUIRE(linkedList->head == linkedList->tail);
    }

    SECTION("addAtIndex using index zero (first element)") {
        linkedList = new SinglyLinkedList();
        REQUIRE(linkedList->addAtIndex(0, 0) == true);
        REQUIRE(linkedList->addAtIndex(0, 1) == true);
        REQUIRE(linkedList->head->value == 1);
        REQUIRE(linkedList->tail->value == 0);
    }

    SECTION("addAtIndex using index as same as size of linked list") {
        linkedList = new SinglyLinkedList();
        linkedList->addAtHead(0);
        REQUIRE(linkedList->addAtIndex(1, 1) == true);
        REQUIRE(linkedList->tail->value == 1);
    }

    SECTION("deleteAtIndex using index which is higher than size of linked list") {
        linkedList = new SinglyLinkedList();
        linkedList->addAtHead(0);
        REQUIRE(linkedList->deleteAtIndex(1) == false);
    }

    SECTION("deleteAtIndex using index which points to a head (zero)") {
        linkedList = new SinglyLinkedList();
        linkedList->addAtHead(0);
        REQUIRE(linkedList->deleteAtIndex(0) == true);
        REQUIRE(linkedList->head == nullptr);
    }

    SECTION("deleteAtIndex using index which points to tail") {
        linkedList = new SinglyLinkedList();
        linkedList->addAtHead(0);
        linkedList->addAtTail(1);
        REQUIRE(linkedList->deleteAtIndex(1) == true);
        REQUIRE(linkedList->tail->value == 0);
    }

}