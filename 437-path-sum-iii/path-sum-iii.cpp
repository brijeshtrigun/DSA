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
    void path(TreeNode* node, long long remain, int &count){
        if(node == NULL) return;
        remain -= node->val;
        if(remain == 0) 
        count++;
        path(node->left, remain, count);
        path(node->right, remain, count);
    }
    int pathSum(TreeNode* root, int targetSum) {
       if(root == NULL) return 0;
       int count = 0;
       path(root, targetSum, count);
       count+= pathSum(root->left, targetSum);
       count += pathSum(root->right, targetSum);
       return count;
    }
};