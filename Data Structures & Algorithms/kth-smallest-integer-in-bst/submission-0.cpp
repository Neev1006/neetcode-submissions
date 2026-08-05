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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        int cnt = 1;
        TreeNode* curr = root;
        while(true){
            if(curr){
                st.push(curr);
                curr = curr->left;
            }
            else{
                if(cnt == k){
                    return st.top()->val;
                }
                cnt++;
                curr = st.top();
                st.pop();
                curr = curr->right;
            }
        }
        return 0;
    }
};
