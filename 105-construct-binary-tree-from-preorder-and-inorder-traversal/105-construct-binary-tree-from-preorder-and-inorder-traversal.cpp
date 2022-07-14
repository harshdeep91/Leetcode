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
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n=pre.size();
       TreeNode* first, *t;
        int j, k, l, r, index;
        unordered_map<int, TreeNode*> m;
        unordered_map<int,int> mp;
        for (int i = 0; i < n; i++)
          mp[in[i]]=i;
        for (int i = 0; i < n; i++)
        {
            t = new TreeNode(pre[i]);
            if (i == 0)
            {
                first = t;
                m[pre[i]] = t;
                continue;
            }
            index = mp[pre[i]];
            j = 0;
            k = n - 1;
            l = -1;
            r = -1;
            while (j < k)
            {
                if (j < index)
                {
                    if (m[in[j]])
                        l = j;
                    j++;
                }
                if (k > index)
                {
                    if (m[in[k]])
                        r = k;
                    k--;
                }
            }
            if (l >= 0 && !m[in[l]]->right)
                m[in[l]]->right = t;
            else
                m[in[r]]->left = t;

            m[pre[i]] = t;
        }
        return first;
         
    }
};