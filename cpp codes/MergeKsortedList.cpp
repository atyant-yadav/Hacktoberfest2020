struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};

class Solution {
public:

    ListNode *mergeKLists(vector<ListNode *> &lists) { //priority_queue
        priority_queue<ListNode *, vector<ListNode *>, compare> q;
        for (auto l : lists) {
            if (l)  q.push(l);
        }
        if (q.empty())  return NULL;

        ListNode* result = q.top();
        q.pop();

        if (result->next) q.push(result->next);
        ListNode* tail = result;
        while (!q.empty()) {
            tail->next = q.top();
            q.pop();
            tail = tail->next;
            if (tail->next) q.push(tail->next);
        }
        tail->next = NULL;
        return result;
    }
};