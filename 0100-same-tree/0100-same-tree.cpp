class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> st1,st2;
        if(p==NULL && q==NULL) return true;
        if(p==NULL && q!=NULL) return false;
        if(p!=NULL && q==NULL) return false;
        
        while((p || !st1.empty()) &&(q || !st2.empty())){
            if(p && q){
                if(p->val!=q->val) return false;
                st1.push(p);
                st2.push(q);
                p=p->left;
                q=q->left;
            }
            else if(p && q==NULL) return false;
            else if(p==NULL && q) return false;
            else{
                p=st1.top();
                q=st2.top();
                st1.pop();
                st2.pop();
                if(p->right==NULL && q->right!=NULL) return false;
                if(p->right!=NULL && q->right==NULL) return false;
                p=p->right;
                q=q->right;
            }
        }
        if(!st1.empty() &&st2.empty()) return false;
         if(st1.empty() &&!st2.empty()) return false;
        return true;
    }
};