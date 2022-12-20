class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       if(list1==NULL) return list2;
       if(list2==NULL) return list1;
        ListNode* p1=NULL,*p2=NULL, *l1=NULL,*ans=NULL;
        if(list1->val>list2->val){
            p1=list2;
            p1=list2;
            l1=list1;
            ans=list2;
        }
        else{
            p1=list1;
            p1=list1;
            l1=list2;
            ans=list1;
        }
        p2=p1->next;
        while(p1->next!=NULL){
            if(p2->val>l1->val){
                p1->next=l1;
                l1=l1->next;
                p1=p1->next;
            }
            else{
                p1->next=p2;
                p2=p2->next;
                p1=p1->next;
            }
        }
        if(l1==NULL) p1->next=p2;
        else if(p2==NULL) p1->next=l1;
        return ans;
    }
};