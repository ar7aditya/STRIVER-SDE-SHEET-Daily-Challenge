class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next==NULL) return head;
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        ListNode* p3 = head->next->next;
        head = head->next;
        while(p2){
            p2->next = p1;
            if(p3 == NULL){
                p1->next = NULL;
                return head;
            }
            if(p3->next){
                p1->next = p3->next;
            }
            else{
                p1->next = p3;
                return head;
            }
            p1 = p3;
            p2 = p3->next;
            p3 = p2->next;
        }
        return head;
    }
};