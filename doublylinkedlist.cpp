#include <iostream>

struct Node {
public:
    Node(int data, Node* nextNode, Node* previousNode) {
        this->data = data;
        this->nextNode = nextNode;
        this->previousNode = previousNode;
    }

    Node* nextNode;
    Node* previousNode;
    int data;
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList(int data) {
        head = new Node(data, nullptr, nullptr);
        tail = head;
        length = 1;
    }

    void Prepend(int data) {
        Node* oldHead = head;
        head = new Node(data, oldHead, nullptr);
        oldHead->previousNode = head;
        length++;
    }

    void Append(int data) {
        Node* finalNode = new Node(data, nullptr, tail);
        tail->nextNode = finalNode;
        tail = finalNode;
        length++;
    }

    void PrintItems() {
        Node* currentNode = head;
        while (currentNode != nullptr) {
            std::cout << currentNode->data << std::endl;
            currentNode = currentNode->nextNode;
        }
    }

    void InsertItem(int index, int data) {

#pragma region HandleEdgeCases

        if (index == 0) {
            Prepend(data);
            return;
        }

        if (index >= length - 1) {
            Append(data);
            return;
        }
#pragma endregion

        Node* leader = TraverseToIndex(index - 1);
        Node* nextToLeader = leader->nextNode;
        Node* newNode = new Node(data, nextToLeader, leader);

        leader->nextNode = newNode;
        nextToLeader->previousNode = newNode;

        length++;
    }

    void Remove(int index) {

#pragma region HandleEdgeCases
        if (index == 0) {
            Node* oldHead = head;
            head = head->nextNode;
            head->previousNode = nullptr;
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
#pragma endregion

        Node* leader = TraverseToIndex(index - 1);
        Node* nextToNextToLeader = leader->nextNode->nextNode;
        delete leader->nextNode;
        leader->nextNode = nextToNextToLeader;
        nextToNextToLeader->previousNode = leader;
        length--;
        return;
    }

    Node* TraverseToIndex(int index) {
        if (index == 0) {
            return head;
        }
        
        int counter = 0;


        Node* currentNode = head;

        while (counter != index) {
            currentNode = currentNode->nextNode;
            counter++;
        }

        return currentNode;
    }

    int length;
};

int main() {
    LinkedList* l = new LinkedList(2);
    l->Append(3);
    l->Append(4);
    l->Remove(1);
    l->Remove(1);
    l->Append(5);
    l->PrintItems();
    
    return 0;
}
