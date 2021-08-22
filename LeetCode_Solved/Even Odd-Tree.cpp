/*

Problem Statement: A binary tree is named Even-Odd if it meets the following conditions:

--> The root of the binary tree is at level index 0, its children are at level index 1, their children are at level        index 2, etc.
--> For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from        left to right).
--> For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from     left to right).
    Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.

Input: root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
Output: true
Explanation: The node values on each level are:
Level 0: [1]
Level 1: [10,4]
Level 2: [3,7,9]
Level 3: [12,8,6,2]
Since levels 0 and 2 are all odd and increasing, and levels 1 and 3 are all even and decreasing, the tree is Even-Odd.

*/

// BFS: Soln 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        
        if( root == NULL ) {
            
            return true;
        }
        
        queue<TreeNode*> q;
        q.push( root );
        
        int level = 0;
        
        while( !q.empty() ) {
            
            int q_size = q.size();
            int min_val = 0;
            int max_val = INT_MAX;
            
            for( int i = 0; i < q_size; ++i ) {
                
                TreeNode* node = q.front();
                q.pop();
                
                // Check whether the level is even or odd
                if( level %2 == 0 ) {
                    
                    if( node->val %2 == 0 ) {
                        
                        return false;
                    }
                    
                    else if( node->val <= min_val ) {
                        
                        return false;
                    }
                    
                    min_val = node->val;
                }
                
                else if( level %2 == 1 ) {
                    
                    if( node->val %2 == 1 ) {
                        
                        return false;
                    }
                    
                    else if( node->val >= max_val ) {
                        
                        return false;
                    }
                    
                    max_val = node->val;
                }
                
                if( node->left != NULL ) {
                    
                    q.push( node->left );
                }
                
                if( node->right != NULL ) {
                    
                    q.push( node->right );
                }
            }
            ++level;
        }
        return true;
    }
};



/*
Time Complexity: O(n)
Space Complexity: O(n)
*/