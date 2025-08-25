#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertAtBeginning(int x) {
    Node* newNode = new Node();
    newNode->data = x;

    if (head == NULL) {
        newNode->next = newNode; // points to itself
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

// Insert at end
void insertAtEnd(int x) {
    Node* newNode = new Node();
    newNode->data = x;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// Delete from beginning
void deleteAtBeginning() {
    if (head == NULL) {
        cout << "List is Empty\n";
        return;
    }

    if (head->next == head) { // only one node
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    Node* last = head;
    while (last->next != head)
        last = last->next;

    head = head->next;
    last->next = head;
    delete temp;
}

// Delete from end
void deleteAtEnd() {
    if (head == NULL) {
        cout << "List is Empty\n";
        return;
    }

    if (head->next == head) { // only one node
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != head)
        temp = temp->next;

    Node* last = temp->next;
    temp->next = head;
    delete last;
}

// Display list
void display() {
    if (head == NULL) {
        cout << "List is Empty\n";
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtBeginning(5);
    insertAtEnd(30);

    cout << "CLL: ";
    display();

    deleteAtBeginning();
    deleteAtEnd();

    cout << "After Deletion: ";
    display();

    return 0;
}
