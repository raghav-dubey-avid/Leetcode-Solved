class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        
        
        unordered_set<int> st;
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr != NULL){
            
            if(st.find(curr->val) != st.end()){
                
                prev->next = curr->next;
                delete (curr);
            }
            else{
                
                st.insert(curr->val);
                prev = curr;
            }
            curr = prev->next;
        }
        return head;
    }
};