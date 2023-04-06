<h1>
I created a <b>C++ Linked List Data Structure</b> from Scratch.
</h1>
<br>

It's nothing complicated, the file from the [Youtube Video](https://youtu.be/QTb4xGdfC48) can be accessed at singlylinkedlist.cpp.

I've also created a Doubly Linked List for those who need it. (doublylinkedlist.cpp)

It has <b>two classes</b>, one representing the 'Node' Class (Which holds the data and the pointer to the next node) and the 'LinkedList' Class (obviously)

class Node {

public:
	int data = 0;
	Node* nextNode = nullptr;

	Node(int data, Node* nextNode) {
		this->data = data;
		this->nextNode = nextNode;
	}
};
