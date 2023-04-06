#include <iostream>

class Node {

public:
	int data = 0;
	Node* nextNode = nullptr;

	Node(int data, Node* nextNode) {
		this->data = data;
		this->nextNode = nextNode;
	}
};

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

#pragma region InsertFunctions

	//Insert at the beginning of the list
	void Prepend(int data) { //O(1)
		Node* oldHead = head;
		head = new Node(data, oldHead);
		length++;
	}

	//Insert at the end of the list
	void Append(int data) { //O(1)
		Node* finalNode = new Node(data, nullptr);
		tail->nextNode = finalNode;
		tail = finalNode;
		length++;
	}

	//Insert data at index
	void Insert(int index, int data) {

		//Handle Edge Cases
		if (index == 0) {
			Prepend(data);
			return;
		}

		if (index >= length - 1) {
			Append(data);
			return;
		}


		Node* leftNode = TraverseToIndex(index - 1); //O(n)
		Node* rightNode = leftNode->nextNode;
		leftNode->nextNode = new Node(data, rightNode);
		length++;
	}

#pragma endregion

#pragma region RemoveFunctions
	void Remove(int index) {

		if (index == 0) {
			Node* oldHead = head;
			head = head->nextNode;
			delete oldHead;
			oldHead = nullptr;
			length--;
			return;
		}

		if (index >= length - 1) {
			Node* penultimateNode = TraverseToIndex(length - 2);
			delete penultimateNode->nextNode;
			penultimateNode->nextNode = nullptr;
			tail = penultimateNode;
			length--;
			return;
		}

		Node* leftNode = TraverseToIndex(index - 1);
		Node* rightNode = leftNode->nextNode->nextNode;
		delete leftNode->nextNode;
		leftNode->nextNode = rightNode;
		length--;
	}

#pragma endregion
	
	Node* TraverseToIndex(int index) {

		Node* currentNode = head;

		int counter = 0;

		while (counter != index) {
			currentNode = currentNode->nextNode;
			counter++;
		}

		return currentNode;
	}

	//Prints all the items from the Linked List
	void PrintItems() {

		Node* currentNode = head;

		while (currentNode != nullptr) {
			std::cout << currentNode->data << std::endl;
			currentNode = currentNode->nextNode;
		}
	}
};

int main() {
	LinkedList* l = new LinkedList(5);
	l->Append(3);
	l->Append(7);
	l->Insert(1, 9);
	l->Insert(1, 12);
	l->Remove(4);
	l->Append(250);
	l->PrintItems();
	delete l;
	l = nullptr;
	return 0;
}