class Solution {
public:
    ListNode* headptr;
    int len = 0;
    unordered_map<int , int> mp;
    Solution(ListNode* head) {
      headptr = head;
      ListNode* temp = headptr;
      while(temp){
          mp[len] = temp->val;
          len++;
          temp = temp->next;
      }
    }
    
    int getRandom() {
       int rnd_ind = rand()%len;
        return mp[rnd_ind];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */