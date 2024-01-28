//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
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
    Node* addOne(Node *head) 
    {
        if(head==NULL){
            return NULL;
        }
        
        head = reverse(head);
        int carry=1;
        Node* temp = head;
        
        while(temp!=NULL){
            int sum = temp->data + carry;
            
            temp->data = sum%10;
            
            if(sum<10){
                carry = 0;
                break;
            }
            
            temp = temp->next;
            
        }
        
        head = reverse(head);
        
        if(carry == 1){
            Node* newNode = new Node(carry);
            newNode->next = head;
            head = newNode;
        }
        
        return head;
        
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends