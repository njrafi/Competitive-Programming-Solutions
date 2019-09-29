		int getHeight(Node* root){
            int ans = 0;
            if(root->left!=NULL)
                ans = max(getHeight(root->left)+1,ans);
            
            if(root->right!=NULL)
                ans = max(getHeight(root->right)+1,ans);
            
            return ans;
        
        }