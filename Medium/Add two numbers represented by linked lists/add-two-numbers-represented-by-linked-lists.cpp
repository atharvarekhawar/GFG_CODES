//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node* reverse(Node* head){
        Node *prev = NULL;
        Node *curr = head;
        Node *ahead = NULL;
        
        while(curr!=NULL){
            ahead = curr->next;
            curr->next=prev;
            prev = curr;
            curr = ahead;
        }
        
        return prev;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
      first = reverse(first);
      second = reverse(second);
      
      Node* ans = new Node(0);
      
      int carry = 0;
      
      Node* temp1 = first;
      Node* temp2 = second;
      Node* temp3 = ans;
      
      while(temp1!=NULL && temp2!=NULL){
          int sum = temp1->data + temp2->data + carry;
          int value = sum%10;
          carry = sum/10;
          
          
          temp3->next = new Node(value);
          
          temp1=temp1->next;
          temp2=temp2->next;
          temp3=temp3->next;
      }
      
      if(temp1!=NULL){
          while(temp1!=NULL){
          int sum = temp1->data + carry;
          int value = sum%10;
          carry = sum/10;
          
          temp3->next = new Node(value);
          
          temp1=temp1->next;
          temp3=temp3->next;
         }
      }
      
      if(temp2!=NULL){
          while(temp2!=NULL){
          int sum =  temp2->data + carry;
          int value = sum%10;
          carry = sum/10;
          
          temp3->next = new Node(value);
          
          temp2=temp2->next;
          temp3=temp3->next;
        }
      }
      
      
      if(carry!=0){
          temp3->next = new Node(carry);
      }
      
      ans->next = reverse(ans->next);
      
      return ans->next;
      
      
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends