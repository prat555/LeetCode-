class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessHead = new ListNode();
        ListNode* greaterHead = new ListNode();
        ListNode* lessTail = lessHead;
        ListNode* greaterTail = greaterHead;

        while (head) {
            if (head->val < x) {
                lessTail->next = head;
                lessTail = lessTail->next;
            } else {
                greaterTail->next = head;
                greaterTail = greaterTail->next;
            }
            head = head->next;
        }

        lessTail->next = greaterHead->next;
        greaterTail->next = nullptr;

        ListNode* newHead = lessHead->next;
        delete lessHead;
        delete greaterHead;

        return newHead;
    }
};