/*

Problem Statement : Given the root of a binary tree, return the sum of all left leaves.

Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.


Problem Link : https://leetcode.com/problems/sum-of-left-leaves/

*/


// C++ code using recursion : (Method-1)

class Solution {
public:
    
    bool isLeaf ( TreeNode* node ) {
        if ( node == NULL ) {
            return false;
        }
        
        if ( node->left == NULL && node->right == NULL ) {
            return true;
        }
        
        return false;
    }
    
    int sumOfLeftLeaves ( TreeNode* root ) {
        
        int answer = 0;
        
        if ( root != NULL ) {
            
            if ( isLeaf( root->left ) ) {
                answer += root->left->val;
            }
            else {
                answer += sumOfLeftLeaves ( root->left );
            }
            
            answer += sumOfLeftLeaves ( root->right );
        }
        
        return answer;
    }
};

--------------------------------------------------------------------------------------

// Method (2) -> BFS

class Solution {
public:

    bool isLeaf( TreeNode* node ) {
        return node->left == NULL && node->right == NULL;
    }

    int sumOfLeftLeaves( TreeNode* root ) {

        if( root == NULL ) return 0;
        int ans = 0;
        queue<pair<TreeNode*, bool> > q;
        q.push( {root, false} );

        while( !q.empty() ) {

            pair<TreeNode*, bool> tmp = q.front();
            q.pop();
            TreeNode* prc = tmp.first;
            bool isLeft = tmp.second;

            if( isLeft && isLeaf(prc) ) ans += prc->val;
            if( prc->left ) q.push( {prc->left, true} );
            if( prc->right ) q.push( {prc->right, false} );
        }
        return ans;
    }
};