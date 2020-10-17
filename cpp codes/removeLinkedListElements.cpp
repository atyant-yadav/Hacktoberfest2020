//This piece of code removes all elements from a linked list of integers that have value val.
//Input:  1->2->6->3->4->5->6, val = 6
//Output: 1->2->3->4->5

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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        ListNode *prev = nullptr, *curr = head;
        while(curr){
            if(curr->val == val){
                if(!prev) head = curr->next;
                else prev->next = curr->next;
            }else
                prev = curr;
            curr = curr->next;
        }
            
        return head;
    }
};
