class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        ListNode* cur = head;
        
        while(cur){
            ans = (ans << 1) + cur->val;
            cur = cur->next;
        }
        
        return ans;
    }
};