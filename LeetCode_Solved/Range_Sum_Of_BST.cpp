/*
Problem Statement : Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

Problem Link : https://leetcode.com/problems/range-sum-of-bst/


*/

// Solution :

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int count = 0;
        if(root == NULL)
            return 0;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){

            TreeNode* curr = q.front();
            q.pop();

            if(curr->val >= low && curr->val <= high)
                count +=  curr->val;

            if(curr->left)
                q.push(curr->left);

            if(curr->right)
                q.push(curr->right);
        }
        return count;
    }
};