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
    int maxDepthFind(TreeNode* root, int cur_dep){
        if(root == NULL)
            return cur_dep - 1;
        return max(maxDepthFind(root->left, cur_dep+1),maxDepthFind(root->right, cur_dep+1));
    }

    int maxDepth(TreeNode* root) {
        return (maxDepthFind(root, 1));   
    }
};