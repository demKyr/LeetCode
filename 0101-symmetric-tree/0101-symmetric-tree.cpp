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
    bool areSame(TreeNode* l, TreeNode* r){
        if (l == NULL && r != NULL || l != NULL && r == NULL)
            return false;
        else if(l == NULL && r == NULL)
            return true;
        if(l->val != r->val)
            return false;
        return (areSame(l->left,r->right) && areSame(l->right,r->left));
    }

    bool isSymmetric(TreeNode* root) {
        return(areSame(root->left,root->right));
    }
};