# Definition for singly-linked list.
# class ListNode:
#    def __init__(self, x):
#        self.val = x
#        self.next = None

class Solution:
    # @param A : head node of linked list
    # @param B : integer
    # @return the head node in the linked list
    def reverseList(self, A, B):
        test=A
        if((B==1)or(A.next==None)):
            return A
        prev=A
        k=0
        start=A
        curr=A
        prev=None
        for i in range(B-1):
            fut=curr.next
            curr.next=prev
            prev=curr
            curr=fut
        curr=curr.next
        fut.next=prev
        ans=fut
        prev=None
        while(curr!=None):
            now=curr
            for _ in range(B-1):
                fut=curr.next
                curr.next=prev
                prev=curr
                curr=fut
            curr=curr.next
            fut.next=prev
            start.next=fut
            start=now
            prev=None
            
        return ans 
