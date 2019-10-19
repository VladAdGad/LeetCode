
struct DoubleListNode {
    int val = 0;
    DoubleListNode *prev = nullptr;
    DoubleListNode *next = nullptr;
};

class MyLinkedList {
public:
    int size;
    DoubleListNode *head;
    DoubleListNode *tail;

    /** Initialize your data structure here. */
    MyLinkedList() {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (size == 0) {
            return -1;
        }

        if (index > size) {
            return -1;
        }

        DoubleListNode *cur = head;
        for (int i = 0; i != size; ++i) {
            if (i == index) {
                return cur->val;
            } else {
                cur = cur->next;
            }
        }

        return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        auto *node = new DoubleListNode();
        node->val = val;

        if (size == 0) {
            head = node;
            tail = node;
            head->next = tail;
            head->prev = tail;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }

        size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        auto *node = new DoubleListNode();
        node->val = val;

        if (size == 0) {
            tail = node;
            head = node;
            tail->next = tail;
            tail->prev = tail;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }

        size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }

        auto *node = new DoubleListNode();
        node->val = val;

        if (size == 0) {
            head = node;
            tail = node;
            size++;
            return;
        }

        if (index == size) {
            tail->next = node;
            node->prev = tail;
            tail = node;
            size++;
            return;
        }

        if (index == 0) {
            node->next = head;
            head->prev = node;
            head = node;
            size++;
            return;
        }

        DoubleListNode *cur = head->next;
        for (int i = 1; i != size; ++i) {
            if (i == index) {
                node->next = cur;
                node->prev = cur->prev;
                cur->prev->next = node;
                cur->prev = node;
                size++;
                return;
            } else {
                cur = cur->next;
            }
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index > size) {
            return;
        }

        if (index == size - 1) {
            tail->prev->next = nullptr;
            tail = tail->prev;
            size--;
            return;
        }

        if (index == 0) {
            head->next->prev = nullptr;
            head = head->next;
            size--;
            return;
        }

        DoubleListNode *cur = head->next;
        for (int i = 1; i != size; ++i) {
            if (i == index) {
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                size--;
                return;
            } else {
                cur = cur->next;
            }
        }
    }
};

int main() {
    auto *myLinkedList_1 = new MyLinkedList();
    myLinkedList_1->addAtHead(1);
    myLinkedList_1->addAtTail(3);
    myLinkedList_1->addAtIndex(1, 2);
    myLinkedList_1->get(1);
    myLinkedList_1->deleteAtIndex(1);
    myLinkedList_1->get(1);

    auto *myLinkedList_2 = new MyLinkedList();
    myLinkedList_2->get(0);
    myLinkedList_2->addAtIndex(1, 2);
    myLinkedList_2->get(0);
    myLinkedList_2->get(1);
    myLinkedList_2->addAtIndex(0, 1);
    myLinkedList_2->get(0);
    myLinkedList_2->get(1);

    auto *myLinkedList_3 = new MyLinkedList();
    myLinkedList_3->addAtHead(5);
    myLinkedList_3->addAtHead(2);
    myLinkedList_3->deleteAtIndex(1);
    myLinkedList_3->addAtIndex(1, 9);
    myLinkedList_3->addAtHead(4);
    myLinkedList_3->addAtHead(9);
    myLinkedList_3->addAtHead(8);
    myLinkedList_3->get(3);
    myLinkedList_3->addAtTail(1);
    myLinkedList_3->addAtIndex(3, 6);
    myLinkedList_3->addAtHead(3);

    auto *myLinkedList_4 = new MyLinkedList();
    myLinkedList_4->addAtHead(1);
    myLinkedList_4->deleteAtIndex(0);

    auto *myLinkedList_5 = new MyLinkedList();
    myLinkedList_5->addAtHead(1);
    myLinkedList_5->addAtTail(3);
    myLinkedList_5->addAtIndex(1, 2);
    myLinkedList_5->get(1);
    myLinkedList_5->deleteAtIndex(0);
    myLinkedList_5->get(0);

    return 0;
}
