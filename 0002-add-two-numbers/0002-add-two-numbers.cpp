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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int cur_sum = 0;
        int add = 0;
        ListNode* l1_cur = l1;
        ListNode* l2_cur = l2;
        ListNode* ans = new ListNode(0);
        ListNode* head = ans;
        
        while(l1_cur!=nullptr && l2_cur!=nullptr){
            cur_sum = l1_cur->val + l2_cur->val + add;
            if(cur_sum>=10){
                add = 1;
                cur_sum = cur_sum - 10;
            }else{
                add = 0;
            }
            ans->next = new ListNode(cur_sum);
            ans = ans->next;
            l1_cur = l1_cur->next;
            l2_cur = l2_cur->next;
            
        }
        if(l1_cur==nullptr){
            while(l2_cur!=nullptr){
                cur_sum = l2_cur->val+add;
                if(cur_sum >=10){
                    add = 1;
                    cur_sum -= 10;
                }else{
                    add = 0;
                }
                ans->next = new ListNode(cur_sum);
                ans = ans->next;
                l2_cur = l2_cur->next;
            }
        }
        if(l2_cur==nullptr){
            while(l1_cur!=nullptr){
                cur_sum = l1_cur->val+add;
                if(cur_sum >=10){
                    add = 1;
                    cur_sum -= 10;
                }else{
                    add = 0;
                }
                ans->next = new ListNode(cur_sum);
                ans = ans->next;
                l1_cur = l1_cur->next;
            }
        }
        cout<<cur_sum<<endl;
        if(add == 1){
            ans->next = new ListNode(1);
        }
        return head->next;
    }
};