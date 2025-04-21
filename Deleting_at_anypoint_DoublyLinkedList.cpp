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

Node* deleteNode(Node *head, int position) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return head;
    }

    Node *curr = head;

    // Traverse to the node at the given position
    for (int i = 1; curr != nullptr && i < position; i++) {
        curr = curr->next;
    }

    // If the position is out of range
    if (curr == nullptr) {
        cout << "Position out of range." << endl;
        return head;
    }

    // Update the previous node's next pointer
    if (curr->prev != nullptr) {
        curr->prev->next = curr->next;
    } else {
        // If the node to be deleted is the head node
        head = curr->next;
    }

    // Update the next node's prev pointer
    if (curr->next != nullptr) {
        curr->next->prev = curr->prev;
    }

    // Deallocate memory for the deleted node
    delete curr;
    return head;
}

void printList(Node *head) {
    Node *curr = head;
    cout << "Doubly Linked List: ";
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    cout << "Original List: ";
    printList(head);

    head = deleteNode(head, 2); // Delete node at position 2

    cout << "List after deletion: ";
    printList(head);

    return 0;
}