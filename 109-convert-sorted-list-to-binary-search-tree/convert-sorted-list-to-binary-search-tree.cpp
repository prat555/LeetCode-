class Solution {
    public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(head == NULL) return NULL;
        
        if(head->next == NULL) {
            return new TreeNode(head->val);
        }
        
        ListNode* runner = head;
        ListNode* midliner = head;
        ListNode* midPrev = head;
        
        while(runner != NULL && runner->next != NULL) { //test n = 2, 3
            runner = runner->next->next;
            midPrev = midliner;
            midliner = midliner->next;
        }
        
        TreeNode* root = new TreeNode(midliner->val);
        midPrev->next = NULL;
        
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(midliner->next);
        
        return root;
    }
};