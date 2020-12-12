#include <vector>
#include <catch2/catch_all.hpp>

class MyCircularQueue {
private:
    std::vector<int> data;
    int head;
    int tail;

public:
    explicit MyCircularQueue(int size) {
        data = std::vector<int>(size);
        head = -1;
        tail = -1;
    }

    bool enQueue(int value) {
        if (isFull() == true) {
            return false;
        }
        if (isEmpty() == true) {
            head = 0;
        }
        tail = (tail + 1) % data.capacity();
        data[tail] = value;
        return true;
    }

    bool deQueue() {
        if (isEmpty() == true) {
            return false;
        }
        if (head == tail) {
            head = -1;
            tail = -1;
            return true;
        }
        head = (head + 1) % data.size();
        return true;
    }

    [[nodiscard]] int Front() const {
        return isEmpty() == false ? data[head] : -1;
    }

    [[nodiscard]] int Rear() const {
        return isEmpty() == false ? data[tail] : -1;
    }

    [[nodiscard]] bool isEmpty() const {
        return head == -1;
    }

    [[nodiscard]] bool isFull() const {
        return ((tail + 1) % data.capacity()) == head;
    }
};

TEST_CASE("Circular Queue", "[Data Structures]") {

    MyCircularQueue *myCircularQueue;

    myCircularQueue = new MyCircularQueue(3);
    REQUIRE(myCircularQueue->enQueue(1) == true);
    REQUIRE(myCircularQueue->enQueue(2) == true);
    REQUIRE(myCircularQueue->enQueue(3) == true);
    REQUIRE(myCircularQueue->enQueue(4) == false);
    REQUIRE(myCircularQueue->Rear() == 3);
    REQUIRE(myCircularQueue->isFull() == true);
    REQUIRE(myCircularQueue->deQueue() == true);
    REQUIRE(myCircularQueue->enQueue(4) == true);
    REQUIRE(myCircularQueue->Rear() == 4);

    myCircularQueue = new MyCircularQueue(10);
    REQUIRE(myCircularQueue->enQueue(5) == true);
    REQUIRE(myCircularQueue->deQueue() == true);
    REQUIRE(myCircularQueue->Front() == -1);
    REQUIRE(myCircularQueue->Rear() == -1);
    REQUIRE(myCircularQueue->isFull() == false);
    REQUIRE(myCircularQueue->isEmpty() == true);

    myCircularQueue = new MyCircularQueue(6);
    REQUIRE(myCircularQueue->enQueue(6) == true);
    REQUIRE(myCircularQueue->Rear() == 6);
    REQUIRE(myCircularQueue->Rear() == 6);
    REQUIRE(myCircularQueue->deQueue() == true);
    REQUIRE(myCircularQueue->Rear() == -1);
    REQUIRE(myCircularQueue->deQueue() == false);
    REQUIRE(myCircularQueue->Front() == -1);
    REQUIRE(myCircularQueue->deQueue() == false);
    REQUIRE(myCircularQueue->deQueue() == false);
    REQUIRE(myCircularQueue->deQueue() == false);

    myCircularQueue = new MyCircularQueue(8);
    REQUIRE(myCircularQueue->enQueue(3) == true);
    REQUIRE(myCircularQueue->enQueue(9) == true);
    REQUIRE(myCircularQueue->enQueue(5) == true);
    REQUIRE(myCircularQueue->enQueue(0) == true);
    REQUIRE(myCircularQueue->deQueue() == true);
    REQUIRE(myCircularQueue->deQueue() == true);
    REQUIRE(myCircularQueue->isEmpty() == false);
    REQUIRE(myCircularQueue->isEmpty() == false);
    REQUIRE(myCircularQueue->Rear() == 0);
    REQUIRE(myCircularQueue->Rear() == 0);
    REQUIRE(myCircularQueue->deQueue() == true);

    myCircularQueue = new MyCircularQueue(4);
    REQUIRE(myCircularQueue->enQueue(2) == true);
    REQUIRE(myCircularQueue->enQueue(3) == true);
    REQUIRE(myCircularQueue->enQueue(4) == true);
    REQUIRE(myCircularQueue->deQueue() == true);
    REQUIRE(myCircularQueue->deQueue() == true);
    REQUIRE(myCircularQueue->enQueue(5) == true);
    REQUIRE(myCircularQueue->enQueue(3) == true);
    REQUIRE(myCircularQueue->Front() == 4);
    REQUIRE(myCircularQueue->enQueue(5) == true);
    REQUIRE(myCircularQueue->Rear() == 5);
    REQUIRE(myCircularQueue->enQueue(6) == false);
    REQUIRE(myCircularQueue->enQueue(3) == false);
    REQUIRE(myCircularQueue->Rear() == 5);
    REQUIRE(myCircularQueue->deQueue() == true);
    REQUIRE(myCircularQueue->Front() == 5);
    REQUIRE(myCircularQueue->deQueue() == true);
    REQUIRE(myCircularQueue->Front() == 3);

}
