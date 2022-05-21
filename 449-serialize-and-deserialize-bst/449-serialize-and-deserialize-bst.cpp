/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    TreeNode *p;
    string ans;
public:
    void inorder(TreeNode* root)
    {
        if(root)
        {
            ans+=to_string(root->val)+",";
            inorder(root->left);
            inorder(root->right);
        }
    }
     TreeNode* insert(TreeNode* root,int x)
    {
        if(root)
        {
            if(root->val>x)
            root->left=insert(root->left,x);
            else
            root->right=insert(root->right,x);
        }
        else
        {
            root=new TreeNode(x);
        }
         return root;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ans.clear();
         inorder(root);
        // cout<<ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int count,i=0;
        TreeNode* head=0;
        while(i<data.size())
        {
            count=0;
              while(data[i]!=',')
              {
                  count*=10;
                  count+=(data[i]-'0');
                  i++;
              }
            head=insert(head,count);
            i++;
        }
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;