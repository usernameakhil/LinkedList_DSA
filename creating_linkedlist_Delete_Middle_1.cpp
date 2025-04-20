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

// Function to find the middle of the linked list
NODE* FindMiddle(NODE* head) {
    if (head == NULL) {
        return NULL; // If the list is empty
    }
    
    NODE* slow = head; // Pointer that moves one step at a time
    NODE* fast = head; // Pointer that moves two steps at a time
    
    // Move fast pointer two steps and slow pointer one step
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next; // Move slow pointer one step
        fast = fast->next->next; // Move fast pointer two steps
    }
    
    return slow; // Slow pointer will be at the middle node
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
    
    // Find the middle of the linked list
    NODE* middleNode = FindMiddle(Head);
    
    // Print the middle node
    if (middleNode != NULL) {
        cout << "Middle of the Linked List: " << middleNode->data << endl;
    } else {
        cout << "The linked list is empty." << endl;
    }
    
    return 0;
}