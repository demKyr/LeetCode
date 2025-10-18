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
    void invertT(TreeNode* p){
        if(p == NULL)
            return;
        // TreeNode *p_temp=new TreeNode(); // this would be wrong, it creates a memory leak
        TreeNode *p_temp = p->left;
        p->left = p->right;
        p->right = p_temp;
        // delete p_temp; // this would be wrong, it deletes p->left
        invertT(p->left);
        invertT(p->right);
        return;
    }

    TreeNode* invertTree(TreeNode* root) {
        invertT(root);
        return(root);
    }
};