#include <bits/stdc++.h>
using namespace std;

class NODE {
public:
    int data;
    NODE *next;
    NODE *prev; // Pointer to the previous node

    NODE(int value) {
        data = value;
        next = NULL;
        prev = NULL; // Initialize previous pointer to NULL
    }
};

int main() {
    NODE *head = NULL; // Initialize head to NULL
    int arr[] = {1, 2, 3, 4, 5};

    // Adding elements at the beginning of the doubly linked list
    for (int i = 0; i < 5; i++) {
        NODE *temp = new NODE(arr[i]); // Create a new node

        if (head == NULL) {
            head = temp; // If the list is empty, set head to the new node
        } else {
            temp->next = head; // Point the new node's next to the current head
            head->prev = temp; // Point the current head's prev to the new node
            head = temp; // Update head to the new node
        }
    }

    // Print the doubly linked list
    NODE *temp = head;
    cout << "Doubly Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next; // Move to the next node
    }
    cout << endl;

    // Optional: Print the doubly linked list in reverse order
    cout << "Doubly Linked List in Reverse: ";
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next; // Move to the last node
    }
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev; // Move to the previous node
    }
    cout << endl;

    return 0;
}