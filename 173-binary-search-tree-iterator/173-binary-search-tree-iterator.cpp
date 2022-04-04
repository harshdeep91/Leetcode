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
class BSTIterator {
    vector<TreeNode*> v;
    int point=-1;
public:
    void inorder(TreeNode* root)
    {
        if(root)
        {
            inorder(root->left);
            v.push_back(root);
            inorder(root->right);
        }
    }
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
            return v[++point]->val;
    }
    
    bool hasNext() {
        // if(point<v.size())
        // cout<<v[point]->val<<endl;
            return point+1<v.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */