<h1>
I created a **C++ Linked List Data Structure** from Scratch.
</h1>
<br>

The file from the [Youtube Video](https://youtu.be/QTb4xGdfC48) can be accessed at `singlylinkedlist.cpp`

I've also created a Doubly Linked List for those who need it. `doublylinkedlist.cpp`

It has **two classes**, one representing the `Node` Class (Which holds the data and the pointer to the next node)

```cpp
class Node {

public:
	int data = 0;
	Node* nextNode = nullptr;

	Node(int data, Node* nextNode) {
		this->data = data;
		this->nextNode = nextNode;
	}
};
```

And the `LinkedList` Class

```cpp
class LinkedList {
public:
	Node* head;
	Node* tail;
	int length;

	LinkedList(int data)
	{
		head = new Node(data, nullptr);
		tail = head;
		length = 1;
	}
```

These are the basic building blocks, for the entire structure please check the .cpp files
