class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(head==NULL || fast->next==NULL || fast->next->next==NULL) return NULL;
        slow = slow->next;
        fast = fast->next->next;
        while( slow!=fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(slow!=fast) return NULL;
        slow = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};