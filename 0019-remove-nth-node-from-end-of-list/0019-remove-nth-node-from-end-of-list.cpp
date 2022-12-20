/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p1=head;
        int c=0;
        while(p1){
            c++;
            p1=p1->next;
        }
        if(n==c) return head->next;
        c=c-n;
        p1=head;
        while(c>1){
            p1=p1->next;
            c--;
        }
        if(p1->next!=NULL)p1->next=p1->next->next;
        else p1->next=NULL;
        return head;
    }
};