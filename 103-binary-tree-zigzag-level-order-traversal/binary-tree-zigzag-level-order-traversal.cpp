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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool lefttoright = 1;
        while(!q.empty()){
            int size = q.size();
            vector<int> row(size);
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                int index = (lefttoright) ? i : (size-1-i);
                row[index] = curr->val;
                if(curr->left != NULL){
                    q.push(curr->left);
                }
                if(curr->right != NULL){
                    q.push(curr->right);
                }

            }
            lefttoright = !lefttoright;
            ans.push_back(row);

        }
        return ans;
    }
};