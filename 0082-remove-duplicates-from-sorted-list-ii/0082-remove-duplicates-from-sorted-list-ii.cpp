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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
       
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = slow->next;
        
        while(slow->next != NULL && slow->next->next != NULL){
            if(slow->next->val == slow->next->next->val){
                fast = slow->next;
                while(fast != NULL && slow->next->val == fast->val){
                    fast = fast->next;
                }
                slow->next = fast;
            }else{
                slow = slow->next;
            }
            
            
            
            
        }
        return dummy->next;
    }
};