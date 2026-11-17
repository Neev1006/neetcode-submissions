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
    int f(TreeNode* root){
        if(!root)return 0;
        
        TreeNode* l = root->left;
        TreeNode* r = root->right;

        return 1 + max(f(l),f(r));
    }
    int maxDepth(TreeNode* root) {
        return f(root);
    }
};
