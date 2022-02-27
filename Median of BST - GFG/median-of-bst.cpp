// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



float findMedian(struct Node* node);

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
   Node* root = new Node(stoi(ip[0]));
 
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
           currNode->left = new Node(stoi(currVal));

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
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   //cout << t << endl;
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

      // getline(cin, s);
       
        cout << findMedian(root) << endl;

      // cout<<"~"<<endl;
   }
   return 0;
}// } Driver Code Ends


/*
Structure of the binary Search Tree is as
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
// your task is to complete the Function
// Function should return median of the BST
void count_nodes(struct Node *root, int &cnt){
    if(!root) return;
    cnt += 1;
    count_nodes(root->left, cnt);
    count_nodes(root->right, cnt);
}

void helper_odd (struct Node *root, int &cnt, int &ans){
    if(!root) return;
    helper_odd(root->left, cnt, ans);
    if(cnt == 0 && !ans){
        ans = root->data;
        return;
    }
    cnt -= 1;
    helper_odd(root->right, cnt, ans);
}

void helper_even (struct Node *root, int &cnt, int &prev, float &ans){
    if(!root) return;
    helper_even(root->left, cnt, prev, ans);
    if(cnt == 0 && !ans){
        ans = ((float)(prev + root->data)/2);
        return;
    }
    cnt -= 1;
    prev = root->data;
    helper_even(root->right, cnt, prev, ans);
}

float findMedian(struct Node *root)
{
    int cnt = 0;
    count_nodes(root, cnt);
    if(cnt%2 == 0){
        float ans = 0.0;
        int prev = 0;
        cnt /= 2;
        helper_even(root, cnt, prev, ans);
        return (float)ans;
    }
    else{
        int ans = 0;
        cnt /= 2;
        helper_odd(root, cnt, ans);
        return (float)ans;
    }
    return 0.0;
}