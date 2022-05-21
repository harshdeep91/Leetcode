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
    string ans;
    int i;
public:
    void levelorder(TreeNode* root)
    {
        if(!root)return;
        queue<TreeNode*> q;
        q.push(root);
        ans+=to_string(root->val)+",";
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                root=q.front();
                q.pop();    
                if(root->left)
                {
                    ans+=to_string(root->left->val)+",";
                    q.push(root->left);
                }
                else 
                    ans+="N,";
                    
                if(root->right)
                {
                    ans+=to_string(root->right->val)+",";
                    q.push(root->right);
                }
                else 
                    ans+="N,";
            }
            
        }
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ans.clear();
         levelorder(root);
        // cout<<ans<<endl;
        return ans;
    }
     int value()
     {
         int count=0,neg=1;
         if(ans[i]=='-')
             neg=-1,i++;
         while(ans[i]!=',')
              {
                  count*=10;
                  count+=(ans[i]-'0');
                  i++;
              }
         i++;
         // cout<<count<<" ";
         return count*neg;
     }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)
            return 0;
        TreeNode* head=0,*last;
        ans=data,i=0;
        // cout<<ans<<endl;
        queue<TreeNode*> q;
        head=new TreeNode(value());
        q.push(head);
        while(!q.empty())
        {
            last=q.front();
            q.pop();
            if(i<data.size()&&data[i]!='N')//left child exist
            {
                last->left=new TreeNode(value  ());
                // cout<<last->val<<" L "<<last->left->val<<endl;
                q.push(last->left);
            }
            else i+=2;
            if(i<data.size()&&data[i]!='N')//right child exist
            {
                last->right=new TreeNode(value());
                // cout<<last->val<<" R "<<last->right->val<<endl;
                q.push(last->right);
            }else i+=2;
        }
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));