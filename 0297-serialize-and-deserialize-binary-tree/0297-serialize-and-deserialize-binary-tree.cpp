
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string s="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode * t=q.front();
            q.pop();
            if(t==NULL) s+="#,";
            else s+=to_string(t->val)+',';
            if(t!=NULL){ 
                q.push(t->left);
                q.push(t->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str; 
        getline(s, str , ',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode * t=q.front();q.pop();
            getline(s,str,',');
            if(str=="#") {
                t->left=NULL;
            }
            else {
                TreeNode* leftNode = new TreeNode(stoi(str)); 
                t->left = leftNode; 
                q.push(leftNode);
            }
            getline(s,str,',');
            if(str=="#") {
                t->right=NULL;
            }
            else {
                TreeNode* rightNode = new TreeNode(stoi(str)); 
                t->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

