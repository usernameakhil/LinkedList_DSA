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

// Function to insert a new value at the beginning of the linked list
NODE* InsertAtBeginning(NODE* head, int value) {
    // Base case: if the list is empty, create a new node
    if (head == NULL) {
        return new NODE(value);
    }
    
    // Create a new node and point it to the current head
    NODE* newNode = new NODE(value);
    newNode->next = head;
    
    // Return the new node as the new head
    return newNode;
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
    
    // Insert a new value at the beginning
    Head = InsertAtBeginning(Head, 1); // Inserting 1 at the beginning
    
    // Print the updated linked list
    cout << "Updated Linked List after inserting at the beginning: ";
    PrintLinkedList(Head);
    
    return 0;
}