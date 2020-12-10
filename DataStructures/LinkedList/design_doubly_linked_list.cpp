#include <catch2/catch_all.hpp>

class DoublyListNode {
public:
    int value;
    DoublyListNode *next, *prev;

    explicit DoublyListNode(int value) {
        this->value = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
public:
    DoublyListNode *head;
    DoublyListNode *tail;
    int size;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    [[nodiscard]] int get(int index) const {
        if (index >= size) {
            return -1;
        }

        DoublyListNode *current;
        if (index < size / 2) {
            current = head;
            while (index > 0) {
                current = current->next;
                index--;
            }
            return current->value;
        } else {
            current = tail;
            index = size - 1 - index;
            while (index > 0) {
                current = current->prev;
                index--;
            }
            return current->value;
        }

        return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    bool addAtHead(int val) {
        auto *newHead = new DoublyListNode(val);

        if (size == 0) {
            head = newHead;
            tail = newHead;
        } else {
            head->prev = newHead;
            newHead->next = head;
            head = newHead;
        }

        size++;
        return true;
    }

    /** Append a node of value val to the last element of the linked list. */
    bool addAtTail(int val) {
        auto *newTail = new DoublyListNode(val);

        if (size == 0) {
            tail = newTail;
            head = newTail;
        } else {
            tail->next = newTail;
            newTail->prev = tail;
            tail = newTail;
        }

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

        DoublyListNode *current;
        if (index < size / 2) {
            current = head;
            while (index > 0) {
                current = current->next;
                index--;
            }
        } else {
            current = tail;
            index = size - 1 - index;
            while (index > 0) {
                current = current->prev;
                index--;
            }
        }

        auto *newNode = new DoublyListNode(val);
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
        size++;
        return true;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    bool deleteAtIndex(int index) {
        if (size == 0) {
            return false;
        }

        if (index >= size) {
            return false;
        }

        if (index == 0) {
            head->prev = nullptr;
            head = head->next;
            size--;
            return true;
        }

        if (index == size - 1) {
            tail = tail->prev;
            tail->next->prev = nullptr;
            tail->next = nullptr;
            size--;
            return true;
        }

        DoublyListNode *current;
        if (index < size / 2) {
            current = head;
            while (index > 0) {
                current = current->next;
                index--;
            }
        } else {
            current = tail;
            index = size - 1 - index;
            while (index > 0) {
                current = current->prev;
                index--;
            }
        }

        current->prev->next = current->next;
        current->prev->next->prev = current->prev;
        current->next = nullptr;
        current->prev = nullptr;
        size--;
        return true;
    }

};


TEST_CASE("Doubly Linked List", "[Data Structures]") {
    DoublyLinkedList *linkedList;

    SECTION("get using empty linked list") {
        linkedList = new DoublyLinkedList();
        REQUIRE(linkedList->size == 0);
        REQUIRE(linkedList->get(0) == -1);
    }

    SECTION("get using index which is higher than size of linked list") {
        linkedList = new DoublyLinkedList();
        linkedList->addAtHead(0);
        REQUIRE(linkedList->size == 1);
        REQUIRE(linkedList->get(1) == -1);
    }

    SECTION("get last element") {
        linkedList = new DoublyLinkedList();
        linkedList->addAtHead(0);
        linkedList->addAtHead(1);
        linkedList->addAtHead(2);
        REQUIRE(linkedList->size == 3);
        REQUIRE(linkedList->get(2) == 0);
    }

    SECTION("get first element") {
        linkedList = new DoublyLinkedList();
        linkedList->addAtHead(0);
        linkedList->addAtHead(1);
        linkedList->addAtHead(2);
        REQUIRE(linkedList->size == 3);
        REQUIRE(linkedList->get(0) == 2);
    }

    SECTION("get middle element") {
        linkedList = new DoublyLinkedList();
        linkedList->addAtHead(0);
        linkedList->addAtHead(1);
        linkedList->addAtHead(2);
        REQUIRE(linkedList->size == 3);
        REQUIRE(linkedList->get(1) == 1);
    }

    SECTION("addAtHead with empty linked list") {
        linkedList = new DoublyLinkedList();
        linkedList->addAtHead(7);
        REQUIRE(linkedList->size == 1);
        REQUIRE(linkedList->get(0) == 7);
        REQUIRE(linkedList->head == linkedList->tail);
    }

    SECTION("addAtHead multiple times") {
        linkedList = new DoublyLinkedList();
        linkedList->addAtHead(0);
        linkedList->addAtHead(1);
        REQUIRE(linkedList->size == 2);
        REQUIRE(linkedList->head != linkedList->tail);
        REQUIRE(linkedList->get(0) == 1);
        REQUIRE(linkedList->get(1) == 0);
        REQUIRE(linkedList->head->value == 1);
        REQUIRE(linkedList->tail->value == 0);
    }

    SECTION("addAtTail with empty linked list") {
        linkedList = new DoublyLinkedList();
        linkedList->addAtTail(0);
        REQUIRE(linkedList->size == 1);
        REQUIRE(linkedList->get(0) == 0);
        REQUIRE(linkedList->tail == linkedList->head);
    }

    SECTION("addAtTail multiple times") {
        linkedList = new DoublyLinkedList();
        linkedList->addAtTail(0);
        linkedList->addAtTail(1);
        REQUIRE(linkedList->size == 2);
        REQUIRE(linkedList->head != linkedList->tail);
        REQUIRE(linkedList->get(0) == 0);
        REQUIRE(linkedList->get(1) == 1);
        REQUIRE(linkedList->head->value == 0);
        REQUIRE(linkedList->tail->value == 1);
    }

    SECTION("addAtIndex using index which is higher than size of linked list") {
        linkedList = new DoublyLinkedList();
        linkedList->addAtHead(0);
        REQUIRE(linkedList->size == 1);
        REQUIRE_FALSE(linkedList->addAtIndex(2, 1));
        REQUIRE(linkedList->size == 1);
    }

    SECTION("addAtIndex using index as same as size of linked list") {
        linkedList = new DoublyLinkedList();
        linkedList->addAtHead(0);
        REQUIRE(linkedList->size == 1);
        REQUIRE(linkedList->addAtIndex(1, 1));
        REQUIRE(linkedList->size == 2);
        REQUIRE(linkedList->tail->value == 1);
    }

    SECTION("addAtIndex using index zero (first element) with empty linked list") {
        linkedList = new DoublyLinkedList();
        REQUIRE(linkedList->size == 0);
        REQUIRE(linkedList->addAtIndex(0, 0));
        REQUIRE(linkedList->size == 1);
        REQUIRE(linkedList->head == linkedList->tail);
    }

    SECTION("addAtIndex using index zero (first element)") {
        linkedList = new DoublyLinkedList();
        linkedList->addAtHead(0);
        REQUIRE(linkedList->size == 1);
        REQUIRE(linkedList->addAtIndex(0, 1));
        REQUIRE(linkedList->size == 2);
        REQUIRE(linkedList->head->value == 1);
        REQUIRE(linkedList->tail->value == 0);
    }

    SECTION("addAtIndex where index is less as twice then size") {
        linkedList = new DoublyLinkedList();
        linkedList->addAtHead(0);
        linkedList->addAtHead(1);
        linkedList->addAtHead(2);
        linkedList->addAtHead(3);
        linkedList->addAtHead(4);
        REQUIRE(linkedList->size == 5);
        REQUIRE(linkedList->addAtIndex(1, 5));
        REQUIRE(linkedList->size == 6);
        REQUIRE(linkedList->get(1) == 5);
    }

    SECTION("addAtIndex where index is more as size divided twice") {
        linkedList = new DoublyLinkedList();
        linkedList->addAtHead(0);
        linkedList->addAtHead(1);
        linkedList->addAtHead(2);
        linkedList->addAtHead(3);
        linkedList->addAtHead(4);
        REQUIRE(linkedList->size == 5);
        REQUIRE(linkedList->addAtIndex(3, 5));
        REQUIRE(linkedList->size == 6);
        REQUIRE(linkedList->get(3) == 5);
    }

    SECTION("addAtIndex where index is on the middle") {
        linkedList = new DoublyLinkedList();
        linkedList->addAtHead(0);
        linkedList->addAtHead(1);
        linkedList->addAtHead(2);
        linkedList->addAtHead(3);
        linkedList->addAtHead(4);
        REQUIRE(linkedList->size == 5);
        REQUIRE(linkedList->addAtIndex(2, 5));
        REQUIRE(linkedList->size == 6);
        REQUIRE(linkedList->get(2) == 5);
    }

    SECTION("deleteAtIndex when list is empty") {
        linkedList = new DoublyLinkedList();
        REQUIRE(linkedList->size == 0);
        REQUIRE_FALSE(linkedList->deleteAtIndex(7));
        REQUIRE(linkedList->size == 0);
    }

    SECTION("deleteAtIndex using index which is higher than size of linked list") {
        linkedList = new DoublyLinkedList();
        linkedList->addAtHead(0);
        REQUIRE(linkedList->size == 1);
        REQUIRE_FALSE(linkedList->deleteAtIndex(1));
        REQUIRE(linkedList->size == 1);
    }

    SECTION("deleteAtIndex using index which points to the head (zero)") {
        linkedList = new DoublyLinkedList();
        linkedList->addAtHead(0);
        REQUIRE(linkedList->size == 1);
        REQUIRE(linkedList->deleteAtIndex(0));
        REQUIRE(linkedList->size == 0);
        REQUIRE(linkedList->head == nullptr);
    }

    SECTION("deleteAtIndex using index which points to the tail") {
        linkedList = new DoublyLinkedList();
        linkedList->addAtHead(0);
        linkedList->addAtTail(1);
        REQUIRE(linkedList->size == 2);
        REQUIRE(linkedList->deleteAtIndex(1));
        REQUIRE(linkedList->size == 1);
        REQUIRE(linkedList->tail->value == 0);
    }

    SECTION("deleteAtIndex where index is less as twice then size") {
        linkedList = new DoublyLinkedList();
        linkedList->addAtHead(0);
        linkedList->addAtHead(1);
        linkedList->addAtHead(2);
        linkedList->addAtHead(3);
        linkedList->addAtHead(4);
        REQUIRE(linkedList->size == 5);
        REQUIRE(linkedList->deleteAtIndex(1));
        REQUIRE(linkedList->size == 4);
        REQUIRE(linkedList->get(1) == 2);
    }

    SECTION("deleteAtIndex where index is more as size divided twice") {
        linkedList = new DoublyLinkedList();
        linkedList->addAtHead(0);
        linkedList->addAtHead(1);
        linkedList->addAtHead(2);
        linkedList->addAtHead(3);
        linkedList->addAtHead(4);
        REQUIRE(linkedList->size == 5);
        REQUIRE(linkedList->deleteAtIndex(3));
        REQUIRE(linkedList->size == 4);
        REQUIRE(linkedList->get(3) == 0);
    }

    SECTION("deleteAtIndex where index is on the middle") {
        linkedList = new DoublyLinkedList();
        linkedList->addAtHead(0);
        linkedList->addAtHead(1);
        linkedList->addAtHead(2);
        linkedList->addAtHead(3);
        linkedList->addAtHead(4);
        REQUIRE(linkedList->size == 5);
        REQUIRE(linkedList->deleteAtIndex(2));
        REQUIRE(linkedList->size == 4);
        REQUIRE(linkedList->get(2) == 1);
    }

}
