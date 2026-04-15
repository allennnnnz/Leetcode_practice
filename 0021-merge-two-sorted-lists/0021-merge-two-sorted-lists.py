# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
  

    def insert_at_tail(self,head: ListNode, val: int,tail: ListNode) -> ListNode:
        new_node = ListNode(val)
        if head == None:
            return new_node ,new_node
        else:
            tail.next = new_node # insert it to the end
            return head ,new_node

    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        k = list1
        j = list2
        sorted_list = None
        tail = None
        if k != None and j != None:
            while k and j:
                if k.val <= j.val:
                    sorted_list,tail = self.insert_at_tail(sorted_list,k.val,tail)
                    k = k.next
                else:
                    sorted_list,tail = self.insert_at_tail(sorted_list,j.val,tail)
                    j = j.next

        while k != None:
            sorted_list,tail = self.insert_at_tail(sorted_list,k.val,tail)
            k = k.next

        while j != None:
            sorted_list,tail = self.insert_at_tail(sorted_list,j.val,tail)
            j = j.next

        return sorted_list
            
