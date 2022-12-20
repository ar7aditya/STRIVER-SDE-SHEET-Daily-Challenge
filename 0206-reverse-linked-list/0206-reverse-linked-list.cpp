class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      if(head==NULL || head->next==NULL) return head;
        ListNode* ptr1=head;
      if(head->next->next==NULL) {
          ptr1=head->next;
          ptr1->next=head;
          head->next=NULL;
          return ptr1;
      }
        ptr1=head->next;
      ListNode* ptr2=head->next->next;
        head->next=NULL;
    while(ptr2!=NULL){
        ptr1->next=head;
        head=ptr1;
        ptr1=ptr2;
        ptr2=ptr2->next;
    }
        ptr1->next=head;
        return ptr1;
    }
};