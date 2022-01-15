// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

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
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

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


/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *node)
    {
        Node* p=node;
        unordered_map<int,int> m;
        queue<pair<Node*,int>> q;
        q.push({node,0});
        int size,val;
        while(!q.empty())
        {
            size=q.size();
            while(size--)
            {
                p=q.front().first;
                val=q.front().second;
                q.pop();
            if(!m[val])
            m[val]=p->data;
                if(p->left)
                q.push({p->left,val-1});
                if(p->right)
                q.push({p->right,val+1});
            }
        }
       vector<pair<int,int>>v;
        for(auto p:m)
        v.push_back(p);
        sort(v.begin(),v.end());
        vector<int> s;
        for(auto x:v)
        s.push_back(x.second);
        return s;
    }
    // void preorder(Node *p,unordered_map<int,int> &m,int val)
    // {
    //     if(p)
    //     {
            
    //         preorder(p->left,m,val-1);
    //         preorder(p->right,m,val+1);
    //     }
    // }
  
    // {
        
    //     int val=0;
    //     preorder(root,m,0);
        
    // }

};



// { Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends