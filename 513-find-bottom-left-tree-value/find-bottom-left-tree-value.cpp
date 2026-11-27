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
    int findBottomLeftValue(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int val = 0;
        while(!q.empty()){
            int n = q.size();
            val = q.front().first->val;
            for(int i = 0; i< n; i++){
                int j = q.front().second;
                if(q.front().first->left!=nullptr)
                {
                    q.push({q.front().first->left,j-1});                
                }
                if(q.front().first->right!=nullptr)
                {
                    q.push({q.front().first->right,j+1});
                }
                q.pop();                    
            }
        }
        return val;

    }
};