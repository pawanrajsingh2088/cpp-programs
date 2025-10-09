#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
    cout << "Inserted " << value << " at the end.\n";
}

void deleteNode(int value) {
    if (head == NULL)
        return;

    Node *curr = head, *prev = NULL;

    // If head node itself holds the key
    if (curr->data == value) {
        if (curr->next == head) {
            head = NULL;
            delete curr;
            return;
        }

        // Find last node
        while (curr->next != head)
            curr = curr->next;
        curr->next = head->next;
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Search for node to delete
    curr = head;
    while (curr->next != head && curr->next->data != value)
        curr = curr->next;

    if (curr->next->data == value) {
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
        cout << "Deleted " << value << " from the list.\n";
    } else {
        cout << "Value not found.\n";
    }
}

void display() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    display();
    deleteNode(20);
    display();
    return 0;
}
