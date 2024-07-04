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
    ListNode* mergeNodes(ListNode* head) {
     ListNode* p=head->next;
     ListNode* t=p;
     while(t!=NULL){
        int temp_sum=0;
        while(t->val!=0){
           temp_sum += t->val;  
           t=t->next;
        }
        p->val=temp_sum;
        t=t->next;
        p->next=t;
        p=p->next;
     }  
     return head->next; 
    }
};