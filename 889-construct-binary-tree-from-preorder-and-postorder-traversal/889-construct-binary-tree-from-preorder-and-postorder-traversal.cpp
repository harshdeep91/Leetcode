/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        //see notes what i did
        stack<TreeNode*> s;
        TreeNode *head=new TreeNode(pre[0]),*t;
        s.push(head);
        int A,B,ai,bi;
        for(int i=1;i<pre.size();i++)
        {
            A=s.top()->val;
            B=pre[i];
            //find index if B is before A then it is left child of A 
            for(int j=0;j<pre.size();j++)
                if(post[j]==A)ai=j;
                else if(post[j]==B)bi=j;
            // cout<<A<<" "<<B<<" "<<ai<<" "<<bi<<endl;
            if(bi<ai)//left child or right child on basis of if left occupied
            {
                t=new TreeNode(B);
                if(s.top()->left)//means its a right child
                s.top()->right=t;
                else
                    s.top()->left=t;
                s.push(t);
            }
            else //either right child of this or its parent
            {
                s.pop();
                i--;
            }
                
        }
        return head;
    }
};