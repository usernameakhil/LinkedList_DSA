#include <iostream>
using namespace std;

class NODE {
public:
    int data;
    NODE *next;
    NODE(int value) {
        data = value;
        next = NULL;
    }
};

// Function to create a linked list from an array
NODE* CreateLinkedList(int arr[], int index, int size) {
    // Base case
    if (index == size) {
        return NULL;
    }
    
    NODE *temp = new NODE(arr[index]);
    temp->next = CreateLinkedList(arr, index + 1, size);
    return temp;
}

// Function to delete the last node from the linked list
NODE* DeleteFromEnd(NODE* head) {
    // If the list is empty
    if (head == NULL) {
        cout << "List is already empty." << endl;
        return NULL;
    }
    
    // If the list has only one node
    if (head->next == NULL) {
        delete head; // Delete the only node
        return NULL; // Return NULL as the list is now empty
    }
    
    // Traverse to the second-to-last node
    NODE* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    
    // Delete the last node
    delete current->next; // Delete the last node
    current->next = NULL; // Set the second-to-last node's next to NULL
    
    return head; // Return the head of the modified list
}

// Function to print the linked list
void PrintLinkedList(NODE* head) {
    NODE* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl; // For better output formatting
}

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    // Create linked list from the array
    NODE *Head = CreateLinkedList(arr, 0, size);
    
    // Print the original linked list
    cout << "Original Linked List: ";
    PrintLinkedList(Head);
    
    // Delete the last node
    Head = DeleteFromEnd(Head);
    
    // Print the updated linked list
    cout << "Updated Linked List after deleting from the end: ";
    PrintLinkedList(Head);
    
    // Delete the last node again to demonstrate further deletion
    Head = DeleteFromEnd(Head);
    
    // Print the updated linked list
    cout << "Updated Linked List after deleting from the end again: ";
    PrintLinkedList(Head);
    
    return 0;
}