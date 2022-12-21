class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return NULL;
       ListNode* slow=head,*fast=head;
       while(fast!=NULL && fast->next!=NULL){
           slow=slow->next;
           fast=fast->next->next;
           if(fast==slow) break;
       }
        if(fast==NULL || fast->next==NULL) return NULL;
        fast=head;
        cout<<endl;
        while(fast!=slow){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};