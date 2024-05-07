class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (curr != NULL) {
            int newVal = curr->val * 2;
            if (newVal < 10) {
                curr->val = newVal;
            } 
            else if (prev != nullptr) {
                curr->val = newVal % 10;
                prev->val = prev->val + 1;
            } 
            else {
                head = new ListNode(1, curr);
                curr->val = newVal % 10;
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};