
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        if(head == NULL || head->next == NULL) return head;
        temp = head->next;
        ListNode* nxtPtr = temp->next;
        head->next = NULL;
        while(temp != NULL){
            temp->next = head;
            head = temp;
            temp = nxtPtr;
            if(temp) nxtPtr = temp->next;
        }
        return head;
    }
};