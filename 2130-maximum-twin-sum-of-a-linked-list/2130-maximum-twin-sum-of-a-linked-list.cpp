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
    ListNode* reverse(ListNode* head){
        ListNode* p2 = head->next;
        if(p2 == NULL) return head;
        ListNode* p3 = p2->next;
        while(p2){
            p2->next = head;
            head = p2;
            p2 = p3;
            if(p3) p3 = p3->next;
        }
        return head;
    }
    
    int pairSum(ListNode* head) {
       ListNode* slow = head;
       ListNode* fast = head;
        while(fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        slow = head;
        fast = reverse(fast);
        
        int ans = 0;
        while(slow){
            int temp = slow->val + fast->val;
            ans = max( ans , temp);
            slow = slow->next;
            fast = fast->next;
        }
    return ans;
    }
};