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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        priority_queue< int, vector<int>,greater<int> > pq;
        for(auto s : lists){
            ListNode* start = s;
            while(start){
                pq.push(start->val);
                start = start->next;
            }
        }
        if(pq.empty()) return NULL;
        ListNode* head = new ListNode(pq.top());
        ListNode* p = head;
        pq.pop();
        while(!pq.empty()){
            p->next = new ListNode(pq.top());
            pq.pop();
            p = p->next;
        }
        return head;
    }
};