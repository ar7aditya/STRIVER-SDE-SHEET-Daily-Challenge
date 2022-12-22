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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* p=head;
        int n=1;
        while(p->next){
            n++;
            p=p->next;
        }
        p->next=head;
        p=p->next;
        k=k%n;
        k=n-k;
        while(k>1){
            k--;
            p=p->next;
        }
        head=p->next;
        p->next=NULL;
        return head;
        
    }
};