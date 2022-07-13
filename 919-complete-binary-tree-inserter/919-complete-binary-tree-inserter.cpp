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
class CBTInserter {
    queue<TreeNode*> q1,q2;
    TreeNode *head;
public:
    CBTInserter(TreeNode* root) {
        //complete tree could be made by queue
        //flll the last nodes and prev in q
        q1.push(root);
        head=root;
        while(!q1.empty())
        {
            int size=q1.size();
            while(size--)
            {
                root=q1.front();
                q1.pop();
                //if this node has left and right node simply put in q2;
                if(!root->left||!root->right)
                    q2.push(root);
                if(root->left)
                    q1.push(root->left);
                if(root->right)
                    q1.push(root->right);
            }
        }
    }
    
    int insert(int val) {
        while(1)
        {
            TreeNode *p=q2.front();
            //check if this tree has left or right
            if(!p->left)
            {
                p->left=new TreeNode(val);
                q2.push(p->left);
                return p->val;
            }
            else if(!p->right)
            {
                p->right=new TreeNode(val);
                q2.push(p->right);
                q2.pop();
                return p->val;
            }
        }
        return 0;
    }
    
    TreeNode* get_root() {
     return head;   
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */