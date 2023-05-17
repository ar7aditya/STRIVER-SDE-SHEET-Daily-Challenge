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
class Solution {
public:
    int pairSum(ListNode* head) {
       vector<int> v;
        ListNode* p1 = head;
        while(p1){
            v.push_back(p1->val);
            p1 = p1->next;
        }
        int n = v.size();
        int i = 0 , j = n-1;
        int ans = 0;
        while(i<j){
            int temp = v[i] + v[j];
            ans = max(temp , ans);
            i++;
            j--;
        }
        return ans;
    }
};