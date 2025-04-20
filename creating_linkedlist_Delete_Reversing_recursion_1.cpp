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

// Recursive function to reverse the linked list
NODE* ReverseLinkedList(NODE* head) {
    // Base case: if head is NULL or only one node
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // Recursive case: reverse the rest of the list
    NODE* newHead = ReverseLinkedList(head->next);
    
    // Reverse the current node's pointer
    head->next->next = head;
    head->next = NULL; // Set the current node's next to NULL
    
    return newHead; // Return the new head of the reversed list
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