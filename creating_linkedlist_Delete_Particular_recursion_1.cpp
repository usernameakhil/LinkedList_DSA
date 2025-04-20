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

// Recursive function to delete a node at a particular position
NODE* DeleteAtPosition(NODE* head, int position) {
    // If the list is empty
    if (head == NULL) {
        cout << "List is already empty." << endl;
        return NULL;
    }
    
    // If the position is 0, delete the head node
    if (position == 0) {
        NODE* temp = head;
        head = head->next; // Move head to the next node
        delete temp; // Delete the old head
        return head; // Return the new head
    }
    
    // Recursive case: traverse to the next node
    head->next = DeleteAtPosition(head->next, position - 1);
    
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
    
    // Delete a node at a specific position (e.g., position 2)
    int positionToDelete = 2; // Change this value to delete from a different position
    Head = DeleteAtPosition(Head, positionToDelete);
    
    // Print the updated linked list
    cout << "Updated Linked List after deleting at position " << positionToDelete << ": ";
    PrintLinkedList(Head);
    
    // Delete another node at a different position (e.g., position 0)
    positionToDelete = 0; // Change this value to delete from a different position
    Head = DeleteAtPosition(Head, positionToDelete);
    
    // Print the updated linked list
    cout << "Updated Linked List after deleting at position " << positionToDelete << ": ";
    PrintLinkedList(Head);
    
    return 0;
}