	void levelOrder(Node * root){
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            Node* u = q.front();
            q.pop();
            printf("%d ",u->data);
            
            if(u->left!=NULL)
                q.push((u->left));
            
            if(u->right!=NULL)
                q.push((u->right));
        }
        
  	
  
	}