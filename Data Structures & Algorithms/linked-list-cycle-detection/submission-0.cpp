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
    bool hasCycle(ListNode* head) {
        if(!head || !head->next || !head->next->next) return false;
        ListNode *fast = head->next->next, *slow = head->next;
        while(fast != slow){
            fast = fast->next;
            if(fast) fast = fast->next;
            if(!fast) return false;
            slow = slow->next;
        }
        return true;
    }
};
