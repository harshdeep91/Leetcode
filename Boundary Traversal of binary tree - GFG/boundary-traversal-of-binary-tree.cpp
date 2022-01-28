// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









 // } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

// 4 10 N 5 5 N 6 7 N 8 8 N 8 11 N 3 4 N 1 3 N 8 6 N 11 11 N 5 8

class Solution {
public:
  void leftBound(Node* root, vector<int>& ans, Node* realRoot)
    {
        if(!root)
            return;
        if(!realRoot->left)
        {
            ans.push_back(root->data);
            return;
        }
        if(!root->left && !root->right)
            return;
        ans.push_back(root->data);
        if(root->left)
            leftBound(root->left,ans,realRoot);
        else
            leftBound(root->right,ans,realRoot);
    }
    
    void appendLeaf(Node* root, vector<int>& ans, Node* &lastLeafRef)
    {
        if(!root)
            return;
        if(!root->left && !root->right)
        {
            lastLeafRef=root;
            ans.push_back(root->data);
        }
        appendLeaf(root->left, ans, lastLeafRef);
        appendLeaf(root->right, ans, lastLeafRef);
    }
    
    void rightBound(Node* root, vector<int>& ans, Node* lastLeafRef, Node* realRoot)
    {
        if(!root)
            return;
        if(!realRoot->right)
            return;
        if(root->right)
            rightBound(root->right,ans,lastLeafRef,realRoot);
        else
            rightBound(root->left,ans,lastLeafRef,realRoot);
        if(root!=realRoot && root!=lastLeafRef)
            ans.push_back(root->data);
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        Node* lastLeafRef=nullptr;
        if(!root)
            return ans;
        leftBound(root, ans, root);
        appendLeaf(root, ans, lastLeafRef);
        rightBound(root, ans, lastLeafRef, root);
        
        return ans;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends