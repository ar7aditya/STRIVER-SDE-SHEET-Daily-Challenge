class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q1;
        q1.push(root);
        while(root && !q1.empty()){
            int n=q1.size();
            Node* rightnode=NULL;
            for(int i=0;i<n;i++){
                Node* cur=q1.front();
                q1.pop();
                cur->next=rightnode;
                rightnode=cur;
                 if(cur->right) q1.push(cur->right);
                if(cur->left) q1.push(cur->left);
            }
        }
        return root;
    }
};