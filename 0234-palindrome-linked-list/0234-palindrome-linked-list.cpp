class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL) return true;
        int c1=0;
        ListNode* p1=head,*p2=head,*fe=NULL;
        while(p1){
            c1++;
            p1=p1->next;
        }
        if(c1%2==0) c1=c1/2+1;
        else c1=c1/2+2;
        p1=head;
        while(c1>2){
            p2=p2->next;
            c1--;
        }
        fe=p2;
        p2=p2->next;  
        if(p2->next==NULL) {
            if(p1->val==p2->val) return true;
            return false;
        }
        ListNode* p3=NULL,*p4=NULL;
        p3=p2->next;
        if(p3->next)p4=p3->next;
        p2->next=NULL;
        while(p3){
           p3->next=p2;
            p2=p3;
            p3=p4;
            if(p4)p4=p4->next;
        }
        fe->next=p2;

        while(p2){
            if(p1->val!=p2->val) return false;
            p2=p2->next;
            p1=p1->next;
        }
        return true;
    }
};