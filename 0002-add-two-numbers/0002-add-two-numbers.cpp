class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* p1=l1;
       ListNode* p2=l2; 
        int carry=0;
        ListNode* ans=new ListNode(-1);
        ListNode* d=ans;
        int v1=0,v2=0,sum=0;
        while(p1!=NULL || p2!=NULL){
            v1=0,v2=0;
            if(p1) v1=p1->val;
            if(p2) v2=p2->val;
            sum=v1+v2+carry;
            carry=sum/10;
            d->next=new ListNode(sum%10);
            d=d->next;
           if(p1) p1=p1->next;
            if(p2)p2=p2->next;
        }
        if(carry!=0)  d->next=new ListNode(carry);
      return ans->next;
    }
};