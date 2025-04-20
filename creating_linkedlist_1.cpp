//addind at the starting
#include <bits/stdc++.h>
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
int main(){
    NODE *head;
    int arr[]={1,2,3,4,5};
    for(int i=0;i<=4;i++){
    if(head==NULL){
        head ==new NODE(arr[i]);
    }
    else{
        NODE *temp;
        temp=new NODE(arr[i]);
        temp-> next=head;
        head=temp;
    }
    
NODE *temp=head;
 cout<<temp->data<<"  ";
temp=temp->next;}
}