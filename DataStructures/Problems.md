# Design Circular Queue
Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".
  
One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.
  
Your implementation should support following operations:
- **MyCircularQueue(k)**: Constructor, set the size of the queue to be k.
- **Front**: Get the front item from the queue. If the queue is empty, return -1.
- **Rear**: Get the last item from the queue. If the queue is empty, return -1.
- **enQueue(value)**: Insert an element into the circular queue. Return true if the operation is successful.
- **deQueue()**: Delete an element from the circular queue. Return true if the operation is successful.
- **isEmpty()**: Checks whether the circular queue is empty or not.
- **isFull()**: Checks whether the circular queue is full or not.
  
**Example:**
```
MyCircularQueue circularQueue = new MyCircularQueue(3); // set the size to be 3
circularQueue.enQueue(1);  // return true
circularQueue.enQueue(2);  // return true
circularQueue.enQueue(3);  // return true
circularQueue.enQueue(4);  // return false, the queue is full
circularQueue.Rear();  // return 3
circularQueue.isFull();  // return true
circularQueue.deQueue();  // return true
circularQueue.enQueue(4);  // return true
circularQueue.Rear();  // return 4
```  

**Note:**
- All values will be in the range of [0, 1000].
- The number of operations will be in the range of [1, 1000].
- Please do not use the built-in Queue library.
  

# Duplicate Zeros
Given a fixed length array **arr** of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written.

Do the above modifications to the input array **in place**, do not return anything from your function.

**Example 1:**
```
Input: [1,0,2,3,0,4,5,0]
Output: null
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
```
**Example 2:**
```
Input: [1,2,3]
Output: null
Explanation: After calling your function, the input array is modified to: [1,2,3]
```

**Note:**
- 1 <= arr.length <= 10000
- 0 <= arr[i] <= 9

**Hide Hint #1**
This is a great introductory problem for understanding and working with the concept of in-place operations. The problem statement clearly states that we are to modify the array in-place. That does not mean we cannot use another array. We just don't have to return anything.

**Hide Hint #2**
A better way to solve this would be without using additional space. The only reason the problem statement allows you to make modifications in place is that it hints at avoiding any additional memory.

**Hide Hint #3** 
The main problem with not using additional memory is that we might override elements due to the zero duplication requirement of the problem statement. How do we get around that?

**Hide Hint #4**
If we had enough space available, we would be able to accommodate all the elements properly. The new length would be the original length of the array plus the number of zeros. Can we use this information somehow to solve the problem?

# Find Numbers with Even Number of Digits
Given an array **nums** of integers, return how many of them contain an **even number** of digits.

**Example 1:**
```
Input: nums = [12,345,2,6,7896]
Output: 2
Explanation: 
12 contains 2 digits (even number of digits). 
345 contains 3 digits (odd number of digits). 
2 contains 1 digit (odd number of digits). 
6 contains 1 digit (odd number of digits). 
7896 contains 4 digits (even number of digits). 
Therefore only 12 and 7896 contain an even number of digits.
```
**Example 2:**
```
Input: nums = [555,901,482,1771]
Output: 1 
Explanation: 
Only 1771 contains an even number of digits.
```
**Constraints:**
- **1 <= nums.length <= 500**
- **1 <= nums[i] <= 10^5**

# Find Pivot Index
Given an array of integers nums, write a method that returns the "pivot" index of this array.

We define the pivot index as the index where the sum of all the numbers to the left of the index is equal to the sum of all the numbers to the right of the index.

If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.

**Example 1:**
```
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of index 3.
Also, 3 is the first index where this occurs.
```
**Example 2:**
```
Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.
```
**Constraints:**
- The length of **nums** will be in the range **[0, 10000]**.
- Each element **nums[i]** will be an integer in the range **[-1000, 1000]**.

# Max Consecutive Ones
Given a binary array, find the maximum number of consecutive 1s in this array.

**Example 1:**
```
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. 
             The maximum number of consecutive 1s is 3.
```
**Note:**
- The input array will only contain 0 and 1.
- The length of input array is a positive integer and will not exceed 10,000

**Hint #1**
You need to think about two things as far as any window is concerned. One is the starting point for the window. 
How do you detect that a new window of 1s has started? The next part is detecting the ending point for this window. 
How do you detect the ending point for an existing window? If you figure these two things out, you will be able to detect the windows of consecutive ones. 
All that remains afterward is to find the longest such window and return the size.

# Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

- push(x) -- Push element x onto stack.
- pop() -- Removes the element on top of the stack.
- top() -- Get the top element.
- getMin() -- Retrieve the minimum element in the stack.

**Example 1:**
```
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
```
**Constraints:**
- Methods **pop**, **top** and **getMin** operations will always be called on **non-empty** stacks.

# Design Singly Linked List
Design Linked List

Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. 
Assume all nodes in the linked list are **0-indexed**.

Implement the **MyLinkedList** class:
- **MyLinkedList()** Initializes the **MyLinkedList** object.
- **int get(int index)** Get the value of the **indexth** node in the linked list. If the index is invalid, return **-1**.
- **void addAtHead(int val)** Add a node of value **val** before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
- **void addAtTail(int val)** Append a node of value **val** as the last element of the linked list.
- **void addAtIndex(int index, int val)** Add a node of value **val** before the **indexth** node in the linked list. If **index** equals the length of the linked list, the node will be appended to the end of the linked list. If **index** is greater than the length, the node **will not be inserted**.
- **void deleteAtIndex(int index)** Delete the **indexth** node in the linked list, if the index is valid.

 

**Example 1:**
```
Input
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]

Explanation
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3
```
**Constraints:**
- **0 <= index, val <= 1000**
- Please do not use the built-in LinkedList library.
- At most **2000** calls will be made to **get**, **addAtHead**, **addAtTail**,  **addAtIndex** and **deleteAtIndex**.

# Squares of a Sorted Array
Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

**Example 1:**
```
Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
```
**Example 2:**
```
Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]
```

**Note:**
- **1 <= A.length <= 10000**
- **-10000 <= A[i] <= 10000**
- **A** is sorted in non-decreasing order.
