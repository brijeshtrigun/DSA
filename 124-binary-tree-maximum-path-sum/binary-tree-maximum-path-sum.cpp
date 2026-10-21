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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        calculate(root, maxSum);
        return maxSum;
    }
    int calculate(TreeNode* roots, int &maxSum){
        if(roots == NULL) return 0;
        int lh = max(0, calculate(roots->left, maxSum));
        int rh = max(0, calculate(roots->right, maxSum));
        maxSum = max(maxSum, (lh + rh + roots->val));
        return max(lh, rh) +roots->val; 
    }
};