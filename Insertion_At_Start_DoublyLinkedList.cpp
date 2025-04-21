#include <bits/stdc++.h>
using namespace std;

class NODE {
public:
    int data;
    NODE *next;
    NODE *prev;

    NODE(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

void insertAtStart(NODE *&head, int value) {
    NODE *newNode = new NODE(value); // Create a new node

    if (head == NULL) {
        head = newNode; // If the list is empty, set head to new node
    } else {
        newNode->next = head; // Point new node's next to current head
        head->prev = newNode; // Update current head's prev to new node
        head = newNode; // Update head to new node
    }
}

void printList(NODE *head) {
    NODE *temp = head;
    cout << "Doubly Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next; // Move to the next node
    }
    cout << endl;
}

int main() {
    NODE *head = NULL; // Initialize head to NULL

    // Inserting elements at the start
    insertAtStart(head, 10);
    insertAtStart(head, 20);
    insertAtStart(head, 30);

    // Print the doubly linked list
    printList(head);

    return 0;
}