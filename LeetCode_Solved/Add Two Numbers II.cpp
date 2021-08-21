/* Problem Statement: You are given two non-empty linked lists representing two non-negative integers. The most 		   significant digit comes first and each of their nodes contains a single digit. Add the two numbers 		           and return the sum as a linked list.

   You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]

Problem Link : https://leetcode.com/problems/add-two-numbers-ii/ 

*/


// Method-1 : Using stack naive solution : 


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // Base Case
        if( !l1 ) {
            return l2;
        }
        
        if( !l2 ) {
            return l1;
        }
        
        if( !l1 && !l2 ) {
            return NULL;
        }
        
        stack<int> st1;
        stack<int> st2;
        
        while( l1 != NULL ) {
            st1.push( l1->val );
            l1 = l1->next;
        }
                
        while( l2 != NULL ) {
            st1.push( l2->val );
            l2 = l2->next;
        }
           
        int carry = 0;
        ListNode* result = 0;
        
        while( !st1.empty() || !st2.empty() ) {
            
            int fn = 0, sn = 0;
            
            while( !st1.empty() ) {
                fn = st1.top();
            }
            
            while( !st2.empty() ) {
                sn = st2.top();
            }
            
            int total_val = fn + sn + carry;
            
            // Now create a new node that contains the total value
            ListNode* temp = new ListNode( total_val % 10 );
            carry = total_val / 10;
            
            if( result == NULL ) {
                result = temp;
            }
            else {
                temp->next = result;
                result = temp;
            }
        }
                
        if( carry != 0 ) {
            
            // Create New node to store the carry
            ListNode* carry_node = new ListNode( carry );
            carry_node->next = result;
            result = carry_node;
        }
                
        return result;
    }
};


// Time Complexity: O ( m + n )
// Space Complexity : O ( max( m, n ) ) 




// Method-2: Optimal :


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // Base Case
        if( !l1 && !l2 ) {
            return NULL;
        }
        
        ListNode* l1_ref = l1;
        ListNode* l2_ref = l2;
        
        // Adding zeroes to the start of the smaller list
        
        while( l1_ref || l2_ref ) {
            
            if( l1_ref == NULL ) {
                ListNode* newNode = new ListNode( 0 );
                newNode->next = l1;
                l1 = newNode;
                
                l2_ref = l2_ref->next;
            }    
            else if( l2_ref == NULL ) {
                
                ListNode* newNode = new ListNode( 0 );
                newNode->next = l2;
                l2 = newNode;
                
                l1_ref = l1_ref->next;
            } 
            else {
                
                l1_ref = l1_ref->next;
                l2_ref = l2_ref->next;
            }
        }
        
        int carry = 0;
        ListNode* fakeNode = new ListNode(-1 );
        
        fakeNode->next = addTwoDigit( l1, l2, carry );
        
        if( carry != 0 ) {
            
            ListNode* newNode = new ListNode( carry );
            newNode->next = fakeNode->next;
            fakeNode->next = newNode;
        }
        
        return fakeNode->next;
    }
    
    ListNode* addTwoDigit( ListNode* l1, ListNode* l2, int& carry ) {
        
        if( l1 == NULL && l2 == NULL ) {
            return NULL;
        }
        
        ListNode *newNode = new ListNode(-1);
        newNode->next = addTwoDigit(l1->next, l2->next, carry);
        
        newNode->val = (l1->val + l2->val + carry) % 10;
        carry = (l1->val + l2->val + carry) / 10;
        
        return newNode;
        
    }
};



// Time Complexity: O ( m + n )
// Space Complexity : O ( 1 ) 

