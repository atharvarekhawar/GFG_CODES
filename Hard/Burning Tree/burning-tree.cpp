//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  Node* findNode(Node * root, int start) {
            if (root == NULL) {
                return NULL;
            }

            if (root->data == start) {
                return root;
            }

            Node* left = findNode(root->left, start);
            Node* right = findNode(root->right, start);

            return left == NULL ? right : left;
        }
        int minTime(Node * root, int target) {
            map<Node*, Node*> parent;
            queue<Node*> q;
            q.push(root);

            while (!q.empty()) {
                int size = q.size();

                for (int i = 0; i < size; ++i) {
                    Node* temp = q.front();
                    q.pop();

                    if (temp->left) {
                        q.push(temp->left);
                        parent[temp->left] = temp;
                    }

                    if (temp->right) {
                        q.push(temp->right);
                        parent[temp->right] = temp;
                    }
                }
            }

            Node* startNode = findNode(root, target);

            int totalTime = -1;
            map<Node*, bool> visited;

            q.push(startNode);
            visited[startNode] = true;

            while (!q.empty()) {
                int size = q.size();
                totalTime++;

                for (int i = 0; i < size; ++i) {
                    Node* temp = q.front();
                    q.pop();

                    if (temp->left && !visited[temp->left]) {
                        q.push(temp->left);
                        visited[temp->left] = true;
                    }

                    if (temp->right && !visited[temp->right]) {
                        q.push(temp->right);
                        visited[temp->right] = true;
                    }

                    if (parent[temp] && !visited[parent[temp]]) {
                        q.push(parent[temp]);
                        visited[parent[temp]] = true;
                    }
                }
            }

            return totalTime;
        }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends