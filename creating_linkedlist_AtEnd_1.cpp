// ading at the end of the linkedlist
#include<bits/stdc++.h>
using namespace std;
class NODE
{ public:
    int data;
    NODE *next;
    NODE(int value){
        data=value;
        next=NULL;
            }
};
int main ()

{
    NODE *Head, *Tail;
    Tail= Head = NULL;
    int arr[] = {2,4,6,8, 10};
    // Insert the value at end
    for (int i=0;i<5;i++)
{  
    // Linked list is empty
    if (Head==NULL){
    Head = new NODE(arr[i]);
    Tail = Head;
    }
//Linked list karti hai
else{
    
Tail->next = new NODE(arr [i]);
Tail = Tail->next;
}}

NODE *temp;
temp = Head;
while (temp)

{
cout<<temp->data<<" ";
temp = temp->next;
}}
