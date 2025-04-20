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

// Function to insert a new value at a specific position in the linked list
NODE* InsertAtPosition(NODE* head, int value, int position) {
    NODE* newNode = new NODE(value);
    
    // If inserting at the head (position 0)
    if (position == 0) {
        newNode->next = head;
        return newNode; // New node becomes the new head
    }
    
    // Traverse to the position just before the desired position
    NODE* current = head;
    for (int i = 0; current != NULL && i < position - 1; i++) {
        current = current->next;
    }
    
    // If current is NULL, the position is out of bounds
    if (current == NULL) {
        cout << "Position out of bounds." << endl;
        delete newNode; // Clean up the allocated node
        return head; // Return the original head
    }
    
    // Insert the new node
    newNode->next = current->next;
    current->next = newNode;
    
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
    
    // Insert a new value at a specific position
    int valueToInsert = 5;
    int position = 2; // Insert at position 2
    Head = InsertAtPosition(Head, valueToInsert, position);
    
    // Print the updated linked list
    cout << "Updated Linked List after inserting " << valueToInsert << " at position " << position << ": ";
    PrintLinkedList(Head);
    
    return 0;
}