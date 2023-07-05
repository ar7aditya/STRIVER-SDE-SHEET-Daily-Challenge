class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int> mp;
        ListNode* ptr = headA;
        while(ptr){
            mp[ptr]++;
            ptr = ptr->next;
        }
        ptr = headB;
        while(ptr){
            mp[ptr]++;
            ptr = ptr->next;
        }
        ptr = headA;
        while(ptr){
            if(mp[ptr] == 2){
                return ptr;
            };
            ptr = ptr->next;
        }
        return NULL;
    }
};