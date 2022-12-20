
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head->next==NULL) return head;
        if(head->next->next==NULL) return head->next;
        ListNode* fp=head;
        while(fp!=NULL && fp->next!=NULL){
            head=head->next;
            fp=fp->next->next;
        }
        // if(fp==NULL) return head->next;
        return head;
    }
};