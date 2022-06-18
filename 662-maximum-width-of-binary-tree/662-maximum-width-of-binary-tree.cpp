class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        // using indexing 2*i+1 for left child and 2*i+2 for right child
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            int start=q.front().second;
            int end=q.back().second;
            ans=max(ans,end-start+1);
            for(int i=0;i<n;i++){
                TreeNode* node=q.front().first;
                int p=q.front().second;
                q.pop();
                if(node->left!=NULL){
                    q.push({node->left,(long long)2*p+1});
                }
                if(node->right!=NULL){
                    q.push({node->right,(long long)2*p+2});
                }
                
                
            }
        
        }
        return ans;
        
    }
};