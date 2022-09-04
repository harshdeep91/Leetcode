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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //if they got same column and same row then sort
        //same row can be understood by level order traversal
        //we first insert the values in new col map sort them
        vector<vector<int>> v;
        map<int,vector<int>> m;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            int size=q.size();
            unordered_map<int,multiset<int>> tmp;
            while(size--)
            {
                TreeNode *p=q.front().first;
                int col=q.front().second;
                q.pop();
                tmp[col].insert(p->val);
                if(p->left)
                    q.push({p->left,col-1});
                if(p->right)
                    q.push({p->right,col+1});
            }
            for(auto x:tmp)
            {
                for(auto y:x.second)
                m[x.first].push_back(y);
            }
        }
        for(auto x:m)
            v.push_back(x.second);
        return v;
    }
};