class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q1,q2;
        q1.push(root);
        while(root && !q1.empty()){
            int n=q1.size();
            for(int i=0;i<n;i++){
                Node* cur=q1.front();
                q1.pop();
                if(q1.empty()) cur->next=NULL;
                else cur->next=q1.front();
                if(cur->left) q2.push(cur->left);
                if(cur->right) q2.push(cur->right);
            }
            q1=q2;
             q2 = queue<Node*>(); 
        }
        return root;
    }
};