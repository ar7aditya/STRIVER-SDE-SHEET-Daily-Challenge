class Solution {
public:
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        ListNode* p1=a, *p2=b;
        int c1=0,c2=0;
        while(p1){
            c1++;
            p1=p1->next;
        }
         while(p2){
            c2++;
            p2=p2->next;
        }
        p1=a;p2=b;
        if(c1>c2){
            c1=c1-c2;
            while(c1){
                  p1=p1->next;
                c1--;                            
            }
        }
        else{
            c2=c2-c1;
            while(c2){
                p2=p2->next;
                c2--;
            }
        }
        while(p1->next!=NULL && p2->next!=NULL){
            if(p1==p2) return p1;
            p1=p1->next;
            p2=p2->next;
        }
        if(p1==p2) return p1;
        return NULL;
    }
};