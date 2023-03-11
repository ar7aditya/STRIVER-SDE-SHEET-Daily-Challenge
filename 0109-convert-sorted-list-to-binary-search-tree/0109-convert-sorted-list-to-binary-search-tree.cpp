/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int get_height(TreeNode* root){
        if(root==NULL) return -1;
        int l_height = get_height(root->left);
        int r_height = get_height(root->right);
        return max(l_height,r_height) + 1;
    }
    int get_balance_factor(TreeNode* root){
        if(root==NULL) return 0;
        else return get_height(root->left) - get_height(root->right);
    }
    TreeNode* new_node(int new_val){
        TreeNode* node = new TreeNode(new_val);
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    TreeNode* leftRotate(TreeNode* root){
        TreeNode* new_root = root->right;
        TreeNode* new_root_left = new_root->left;
        new_root->left = root;
        root->right = new_root_left;
        return new_root;
    }
    TreeNode* rightRotate(TreeNode* root){
          TreeNode *new_root = root->left;
          TreeNode *T2 = new_root->right;
          new_root->right = root;
          root->left = T2;
          return new_root;
    }
    TreeNode* push(TreeNode* root , int new_val){
        if(root==NULL){
            return new_node(new_val);
        }
        else{
            if(new_val < root->val){
                root->left = push(root->left , new_val);
            }
             else if(root->val < new_val) {
                root->right = push(root->right , new_val);
            }
        }
        
        int balance_factor = get_balance_factor(root);
        if(balance_factor > 1 && root->left->val > new_val){
            //left left
            return rightRotate(root);
        }
        else if(balance_factor > 1 && root->left->val < new_val){
            //left right
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        else if(balance_factor < -1 && root->right->val < new_val){
            //right right
            return leftRotate(root);
        } 
        else if(balance_factor < -1 && root->right->val > new_val){
            //right left
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* root = NULL;
        while(head!=NULL){
            root = push(root,head->val);
            head = head->next;
        }
        return root;
    }
};