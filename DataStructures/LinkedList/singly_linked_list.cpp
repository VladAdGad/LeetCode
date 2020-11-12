#include <catch2/catch_all.hpp>

class SinglyLinkedListNode {
public:
    int value;
    SinglyLinkedListNode *next;

    explicit SinglyLinkedListNode(int value) {
        this->value = value;
        next = nullptr;
    }
};

class SinglyLinkedList {
public:
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;
    int size = 0;

    /** Initialize your data structure here. */
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
        for (SinglyLinkedListNode *cur = head; count != index + 1; cur = cur->next, ++count) {
            if (count == index) {
                return cur->value;
            }
        }

        return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    bool addAtHead(int val) {
        auto *newNode = new SinglyLinkedListNode(val);

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
        auto *newNode = new SinglyLinkedListNode(val);

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
        for (SinglyLinkedListNode *cur = head; count != index + 1; cur = cur->next, ++count) {
            if (count == index - 1) {
                auto *newNode = new SinglyLinkedListNode(val);
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
        for (SinglyLinkedListNode *cur = head; count != index + 1; cur = cur->next, ++count) {
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

    SECTION("deleteAtIndex using index which is higher than size of linked list"){
        linkedList = new SinglyLinkedList();
        linkedList->addAtHead(0);
        REQUIRE(linkedList->deleteAtIndex(1) == false);
    }

    SECTION("deleteAtIndex using index which points to a head (zero)"){
        linkedList = new SinglyLinkedList();
        linkedList->addAtHead(0);
        REQUIRE(linkedList->deleteAtIndex(0) == true);
        REQUIRE(linkedList->head == nullptr);
    }

    SECTION("deleteAtIndex using index which points to tail"){
        linkedList = new SinglyLinkedList();
        linkedList->addAtHead(0);
        linkedList->addAtTail(1);
        REQUIRE(linkedList->deleteAtIndex(1) == true);
        REQUIRE(linkedList->tail->value == 0);
    }

//    ["MyLinkedList","addAtHead","addAtHead","addAtHead","addAtIndex","deleteAtIndex","addAtHead","addAtTail","get","addAtHead","addAtIndex","addAtHead"]
//    [[],[7],[2],[1],[3,0],[2],[6],[4],[4],[4],[5,0],[6]]
//    ["MyLinkedList","addAtHead","get","addAtHead","addAtHead","deleteAtIndex","addAtHead","get","get","get","addAtHead","deleteAtIndex"]
//    [[],[4],[1],[1],[5],[3],[7],[3],[3],[3],[1],[4]]
//    ["MyLinkedList","addAtHead","addAtTail","addAtTail","get","get","addAtTail","addAtIndex","addAtHead","addAtHead","addAtTail","addAtTail","addAtTail","addAtTail","get","addAtHead","addAtHead","addAtIndex","addAtIndex","addAtHead","addAtTail","deleteAtIndex","addAtHead","addAtHead","addAtIndex","addAtTail","get","addAtIndex","addAtTail","addAtHead","addAtHead","addAtIndex","addAtTail","addAtHead","addAtHead","get","deleteAtIndex","addAtTail","addAtTail","addAtHead","addAtTail","get","deleteAtIndex","addAtTail","addAtHead","addAtTail","deleteAtIndex","addAtTail","deleteAtIndex","addAtIndex","deleteAtIndex","addAtTail","addAtHead","addAtIndex","addAtHead","addAtHead","get","addAtHead","get","addAtHead","deleteAtIndex","get","addAtHead","addAtTail","get","addAtHead","get","addAtTail","get","addAtTail","addAtHead","addAtIndex","addAtIndex","addAtHead","addAtHead","deleteAtIndex","get","addAtHead","addAtIndex","addAtTail","get","addAtIndex","get","addAtIndex","get","addAtIndex","addAtIndex","addAtHead","addAtHead","addAtTail","addAtIndex","get","addAtHead","addAtTail","addAtTail","addAtHead","get","addAtTail","addAtHead","addAtTail","get","addAtIndex"]
//    [[],[84],[2],[39],[3],[1],[42],[1,80],[14],[1],[53],[98],[19],[12],[2],[16],[33],[4,17],[6,8],[37],[43],[11],[80],[31],[13,23],[17],[4],[10,0],[21],[73],[22],[24,37],[14],[97],[8],[6],[17],[50],[28],[76],[79],[18],[30],[5],[9],[83],[3],[40],[26],[20,90],[30],[40],[56],[15,23],[51],[21],[26],[83],[30],[12],[8],[4],[20],[45],[10],[56],[18],[33],[2],[70],[57],[31,24],[16,92],[40],[23],[26],[1],[92],[3,78],[42],[18],[39,9],[13],[33,17],[51],[18,95],[18,33],[80],[21],[7],[17,46],[33],[60],[26],[4],[9],[45],[38],[95],[78],[54],[42,86]]
    auto *obj = new SinglyLinkedList();
    obj->addAtHead(84);
    obj->addAtTail(2);
    obj->addAtTail(39);
    obj->get(3);
    obj->get(1);
    obj->addAtTail(42);
    obj->addAtIndex(1, 80);
    obj->addAtHead(14);
    obj->addAtHead(1);
    obj->addAtTail(53);
    obj->addAtTail(98);
    obj->addAtTail(19);
    obj->addAtTail(12);
    obj->get(2);
    obj->addAtHead(16);
    obj->addAtHead(33);
    obj->addAtIndex(4, 17);
    obj->addAtIndex(6, 8);
    obj->addAtHead(37);
    obj->addAtTail(43);//17
    obj->deleteAtIndex(11);
    obj->addAtHead(80);
    obj->addAtHead(31);
    obj->addAtIndex(13, 23);
    obj->addAtTail(17);
    obj->get(4);
    obj->addAtIndex(10, 0);//21
    obj->addAtTail(21);//good
    obj->addAtHead(73);
    obj->addAtHead(22);//24 good
    obj->addAtIndex(24, 37);//24
    obj->addAtTail(14);
    obj->addAtHead(97);
    obj->addAtHead(8);//27
    obj->get(6);
    obj->deleteAtIndex(17);
    obj->addAtTail(50);
    obj->addAtTail(28);
    obj->addAtHead(76);
    obj->addAtTail(79);
    obj->get(18);//30
    obj->deleteAtIndex(30);//30
    obj->addAtTail(5);
    obj->addAtHead(9);
    obj->addAtTail(83);
    obj->deleteAtIndex(3);
    obj->addAtTail(40);
    obj->deleteAtIndex(26);
    obj->addAtIndex(20, 90);
    obj->deleteAtIndex(30);
    obj->addAtTail(40);
    obj->addAtHead(56);
    obj->addAtIndex(15, 23);
    obj->addAtHead(51);
    obj->addAtHead(21);
    obj->get(26);
    obj->addAtHead(83);
    obj->get(30);
    obj->addAtHead(12);
    obj->deleteAtIndex(8);
    obj->get(4);
    obj->addAtHead(20);
    obj->addAtTail(45);
    obj->get(10);
    obj->addAtHead(56);
    obj->get(18);
    obj->addAtTail(33);
    obj->get(2);
    obj->addAtTail(70);
    obj->addAtHead(57);
    obj->addAtIndex(31, 24);
    obj->addAtIndex(16, 92);
    obj->addAtHead(40);
    obj->addAtHead(23);
    obj->deleteAtIndex(26);
    obj->get(1);
    obj->addAtHead(92);
    obj->addAtIndex(3, 78);
    obj->addAtTail(42);
    obj->get(18);
    obj->addAtIndex(39, 9);
    obj->get(13);
    obj->addAtIndex(33, 17);
    obj->get(51);
    obj->addAtIndex(18, 95);
    obj->addAtIndex(18, 33);
    obj->addAtHead(80);
    obj->addAtHead(23);
    obj->addAtTail(7);
    obj->addAtIndex(17, 46);
    obj->get(33);
    obj->addAtHead(60);
    obj->addAtTail(26);
    obj->addAtTail(4);
    obj->addAtHead(9);
    obj->get(45);
    obj->addAtTail(38);
    obj->addAtHead(95);
    obj->addAtTail(78);
    obj->get(54);
    obj->addAtIndex(42, 86);

//    obj->addAtHead(4);
//    obj->get(1);
//    obj->addAtHead(1);
//    obj->addAtHead(5);
//    obj->deleteAtIndex(3);
//    obj->addAtHead(7);
//    obj->get(3);
//    obj->get(3);
//    obj->get(3);
//    obj->addAtHead(1);
//    obj->deleteAtIndex(4);
//    obj->addAtHead(2);
//    obj->deleteAtIndex(1);
//    obj->addAtHead(2);
//    obj->addAtHead(7);
//    obj->addAtHead(3);
//    obj->addAtHead(2);
//    obj->addAtHead(5);
//    obj->addAtTail(5);
//    int a = obj->get(5);
//    obj->deleteAtIndex(6);
//    obj->deleteAtIndex(4);
//    ["MyLinkedList","addAtHead","deleteAtIndex","addAtHead","addAtHead","addAtHead","addAtHead","addAtHead","addAtTail","get","deleteAtIndex","deleteAtIndex"]
//    [[],[2],[1],[2],[7],[3],[2],[5],[5],[5],[6],[4]]
//    ["MyLinkedList","addAtIndex","addAtIndex","addAtIndex","get"]
//    [[],[0,10],[0,20],[1,30],[0]]
//obj->addAtIndex(0,10);
//obj->addAtIndex(0,20);
//obj->addAtIndex(1,30);
//int a = obj->get(0);
//    ["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
//    [[],[1],[3],[1,2],[1],[0],[0]]
//obj->addAtHead(1);
//obj->addAtTail(3);
//obj->addAtIndex(1,2);
//int a = obj->get(1);
//obj->deleteAtIndex(0);
//int b = obj->get(0);


//    obj->addAtHead(7);
//    obj->addAtHead(2);
//    obj->addAtHead(1);
//    obj->addAtIndex(3, 0);
//    obj->deleteAtIndex(2);
//    obj->addAtHead(6);
//    obj->addAtTail(4);
//    int a = obj->get(4);
//    obj->addAtHead(4);
//    obj->addAtIndex(5, 0);
//    obj->addAtHead(6);
//    SinglyLinkedList *obj = new SinglyLinkedList();
//    obj->addAtHead(1);
//    obj->addAtTail(1);
//    obj->addAtIndex(1, 2);
//    int a = obj->get(1);
//    obj->deleteAtIndex(1);
//    obj->get(1);
//    ["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
//    [[],[1],[3],[1,2],[1],[1],[1]]
}
/**
 * Your SinglyLinkedList object will be instantiated and called as such:
 * SinglyLinkedList* obj = new SinglyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
