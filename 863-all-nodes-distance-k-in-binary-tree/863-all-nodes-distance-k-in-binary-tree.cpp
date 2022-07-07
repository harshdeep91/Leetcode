/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    unordered_map<int,int> dis;
public:
    int assignfirst(TreeNode *root, TreeNode * target)
    {
        if(root)
        {
            int x=assignfirst(root->left,target);
            int y= assignfirst(root->right,target);
            if(root==target)//from here only we assign dis
            {
                dis[root->val]=0;
                return 0;
            }
            else if(x==-1&&y==-1)//dont assign anything
                return -1;
            return dis[root->val]=x==-1?y+1:x+1;
        }
        return -1;
    }
    //simple travel
    void solve(TreeNode* root,int k) {
        if(root)
        {
            //assign the dis if it is not there already
            if(dis.find(root->val)!=dis.end())
            {
                solve(root->left,dis[root->val]+1);
                solve(root->right,dis[root->val]+1);
            }
            else //assign k
            {
                dis[root->val]=k;
                solve(root->left,k+1);
                solve(root->right,k+1);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       //travel tree first assign distance when u are returning
        //only to ancestores
        //travel again but this time with the assigned dis
        assignfirst(root,target);
        solve(root,0);
        vector<int> ans;
        for(auto x:dis)
        {
            cout<<x.first<<" "<<x.second<<endl;
            if(x.second==k)ans.push_back(x.first);
        }
        return ans;
    }
};