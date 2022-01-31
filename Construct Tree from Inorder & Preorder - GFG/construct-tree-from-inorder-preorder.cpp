// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int i;
    int search(int &s,int &e,int in[],int &x)
    {
        int j;
        for(j=s;j<=e;j++)
         if(in[j]==x)
         break;
        return j;
    }
    Node* solve(int s,int e,int in[],int pre[],int n,unordered_map<int,int> &m)
    {
                // cout<<s<<" "<<e<<" "<<i<<endl;

        if(i==n||s>e)
        return 0;
        
        Node *p=new Node(pre[i]);
        int j=m[pre[i]];
        i++;
        // cout<<" "<<index<<" ";
        // cout<<" left ";
        p->left=solve(s,j-1,in,pre,n,m);
        // cout<<" right ";
        p->right=solve(j+1,e,in,pre,n,m);
        return p;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        i=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        m[in[i]]=i;
        return solve(0,n-1,in,pre,n,m);
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends