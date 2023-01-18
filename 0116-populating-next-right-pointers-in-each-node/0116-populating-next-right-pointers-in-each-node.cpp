class Solution {
public:
    Node* f(Node* root){
        if(root==NULL) return NULL;
        Node* L=root->left ,*R=root->right,*N=root->next;
        if(L){
            L->next=R;
            if(N) R->next=N->left;
            f(L);
            f(R);
        }
        return root;
    }
    Node* connect(Node* root) {
        return f(root);
    }
};