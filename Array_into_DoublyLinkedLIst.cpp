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

Node* arrayToDoublyLinkedList(int arr[], int n) {
    Node *head = NULL, *last = NULL;

    for (int i = 0; i < n; i++) {
        Node *new_node = new Node(arr[i]); // Create a new node

        if (head == NULL) {
            head = new_node; // Set head if list is empty
        } else {
            last->next = new_node; // Link the last node to the new node
            new_node->prev = last; // Set the prev of new node to last node
        }
        last = new_node; // Update last to the new node
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
    int arr[] = {10, 20, 30, 40, 50}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]); // Size of the array

    Node *head = arrayToDoublyLinkedList(arr, n); // Convert array to DLL

    // Print the doubly linked list
    printList(head);

    return 0;
}