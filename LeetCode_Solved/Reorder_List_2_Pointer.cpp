//Two pointer solution
//Eg: 1->2->3->4->5->6
//Output : 1->6->2->5->3->4
//T(n) = O(n)
//Idea: split the linked list into two halves using fast and slow pointer.
//Reverse the second half
//And merge it with first half 



class Solution {
public:
    void reorderList(ListNode* head) {
        
        if(!head || !head->next) return;
        
        //head of first half
        ListNode* l1 = head;
        
        //head of second half
        ListNode* slow = head;
        
        //tail of second half
        ListNode* fast = head;
        
        //tail of first half
        ListNode* prev = NULL;
        
        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        
        //reverse the second half
        ListNode* l2 = reverse(slow);
        
        //merge l1 and l2
        merge(l1, l2);
    }
    
    ListNode* reverse(ListNode* head){
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr){
            ListNode* next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        return prev;
    }
    
    void merge(ListNode* l1, ListNode* l2){
        
        while(l1 != NULL){
            
            ListNode* l1_next = l1->next;
            ListNode* l2_next = l2->next;
        
            l1->next = l2;
        
            if(l1_next == NULL){
                break;
            }
        
            l2->next = l1_next;
            l1 = l1_next;
            l2 = l2_next;
        }
    }
};