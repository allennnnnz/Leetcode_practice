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
        int count = 1;
        if(head == NULL){
            return NULL;
        }
        while(ptr->next != NULL){
            ptr = ptr->next;
            count++;
        }
      
        ptr->next = head;
        
        k %= count; 
        for(int i = 0 ; i<count - k  ; i++){
            ptr = ptr->next;
            
        }
       
        head = ptr->next;
        cout<< head->val;
        ptr->next = NULL;
   
        return head;
    }
};