/*

Problem Statement : Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

*/


// Solution in C++

class Solution {
public:
    ListNode* reverseBetween( ListNode* head, int left, int right ) {
        vector<int>v;
        ListNode* left_node = head; 
            for( int i = 1; i < left; i++ ) left_node = left_node->next;

            ListNode* node = left_node;
            for( int i = 0; i < ( right - left + 1 ); i++ ){
                v.push_back( node->val );
                node = node->next;
            }
            reverse( v.begin(), v.end() );
            for( int i = 0; i < v.size(); i++ ){
                left_node->val = v[i];
                left_node = left_node->next;
            }
        return head;      
    }
};