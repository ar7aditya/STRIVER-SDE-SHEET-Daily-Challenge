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
        ListNode* ptr = head;
        int size = 1;
        if(head == NULL || head->next == NULL || k == 0) return head;
        while(ptr->next != NULL){
            ptr = ptr->next;
            size++;
        }
        ptr->next = head;
        ptr = head;
        int i = 1;
        k = (k % size);
        k = size - k;
        while(i < k){
            ptr = ptr->next;
            i++;
        }
        head = ptr->next;
        ptr->next = NULL;
        return head;
    }
};