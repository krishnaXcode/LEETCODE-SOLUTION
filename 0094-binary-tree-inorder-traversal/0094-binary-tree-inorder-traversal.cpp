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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != nullptr || !st.empty()) {
            // Reach the left-most node of the current node
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            
            // Current must be null at this point, so pop from stack
            curr = st.top();
            st.pop();
            
            // Add the value and then shift to the right subtree
            result.push_back(curr->val);
            curr = curr->right;
        }
        
        return result;
    }
};