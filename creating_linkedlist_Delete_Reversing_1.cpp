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

// Function to reverse the linked list
NODE* ReverseLinkedList(NODE* head) {
    NODE* prev = NULL;
    NODE* current = head;
    NODE* next = NULL;

    while (current != NULL) {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the current node's pointer
        prev = current;       // Move prev and current one step forward
        current = next;
    }
    return prev; // New head of the reversed list
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
    
    // Reverse the linked list
    Head = ReverseLinkedList(Head);
    
    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    PrintLinkedList(Head);
    
    return 0;
}