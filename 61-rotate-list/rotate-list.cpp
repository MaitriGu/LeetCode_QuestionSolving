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
      if(k==0||head==NULL||head->next==NULL) return head;
      int length=1;
      ListNode* p=head;
      while(p->next!=NULL){
        length++;
        p=p->next;
      }
      if(length==k) return head;
       k=k % length;
       if(k==0)return head;
      ListNode* slow=head;
      ListNode* fast=head;
      ListNode* dummy=new ListNode();
      while(k!=0){
        fast=fast->next;
        k--;
      }
      while(fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
      }
      dummy->next=slow->next;
      slow->next=NULL;
      fast->next=head;
      return dummy->next;
    }
};