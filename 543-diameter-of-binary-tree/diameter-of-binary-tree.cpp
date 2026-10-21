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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        findheight(root, maxi);
        return maxi;
    }
    private :
    int findheight(TreeNode* root, int &maxi){
        if(root == 0) return 0;
        int lh = findheight(root->left, maxi);
        int rh = findheight(root->right, maxi);
        maxi = max(maxi, lh+rh);
        return 1+ max(lh, rh);
    }
};