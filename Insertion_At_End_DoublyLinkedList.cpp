#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next, *prev;

    Node(int new_data) {
        data = new_data;
        next = prev = nullptr;
    }
};

Node* insertEnd(Node *head, int new_data) {
    Node *new_node = new Node(new_data); // Create a new node

    if (head == NULL) {
        head = new_node; // If the list is empty, set head to new node
    } else {
        Node *curr = head;
        while (curr->next != NULL) {
            curr = curr->next; // Traverse to the last node
        }
        curr->next = new_node; // Set the next of last node to new node
        new_node->prev = curr; // Set prev of new node to last node
    }

    return head; // Return the head of the doubly linked list
}

void printList(Node *head) {
    Node *curr = head;
    cout << "Doubly Linked List: ";
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next; // Move to the next node
    }
    cout << endl;
}

int main() {
    Node *head = NULL; // Initialize head to NULL

    // Inserting elements at the end
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);

    // Print the doubly linked list
    printList(head);

    return 0;
}