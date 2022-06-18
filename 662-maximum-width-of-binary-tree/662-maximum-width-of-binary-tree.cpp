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

    int widthOfBinaryTree(TreeNode* root) {
            
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        long long mx=0,l,r,size,dis;
        while(!q.empty())
        {
             size=q.size(),l=INT_MAX,r=INT_MIN;
            //then start new tree 
              if(size==1) 
              {
                  q.push({q.front().first,0});
                  q.pop();
              }
            while(size--)
            {
                TreeNode* p=q.front().first;
                dis=q.front().second;
                l=min(l,dis);
                r=max(r,dis);
                // cout<<p->val<<" "<<dis<<endl;
                if(dis-l>INT_MAX)return mx;
                q.pop();
                if(p->left)
                    q.push({p->left,2*dis});
                if(p->right)
                    q.push({p->right,2*dis+1});
                mx=max(mx,r-l+1);
            }
        }
        return mx;
    }
};