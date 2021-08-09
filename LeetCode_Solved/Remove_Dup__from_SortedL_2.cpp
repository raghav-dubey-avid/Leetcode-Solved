class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        //Base Case
        if(!head || !head->next)
            return head;
        
        int data = head->val;
        
        if(head->next->val != data){
            head->next = deleteDuplicates(head->next);
            return head;
        }
        while(head != NULL && data == head->val){
            head = head->next;
        }
        
        return deleteDuplicates(head);
        
    }
};