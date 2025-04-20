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

// Function to delete the first node from the linked list
NODE* DeleteFromBeginning(NODE* head) {
    // If the list is empty
    if (head == NULL) {
        cout << "List is already empty." << endl;
        return NULL;
    }
    
    // Store the old head
    NODE* temp = head;
    
    // Move head to the next node
    head = head->next;
    
    // Delete the old head
    delete temp;
    
    return head; // Return the new head
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
    
    // Delete the first node
    Head = DeleteFromBeginning(Head);
    
    // Print the updated linked list
    cout << "Updated Linked List after deleting from the beginning: ";
    PrintLinkedList(Head);
    
    // Delete the first node again to demonstrate further deletion
    Head = DeleteFromBeginning(Head);
    
    // Print the updated linked list
    cout << "Updated Linked List after deleting from the beginning again: ";
    PrintLinkedList(Head);
    
    return 0;
}