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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        return dfs(root, root->val);
    }
private:
    long long dfs(TreeNode* node, int firstMin) {
        if (!node) return -1;
        if (node->val > firstMin) return node->val;
        long long leftMin = dfs(node->left, firstMin);
        long long rightMin = dfs(node->right, firstMin); 
        if (leftMin != -1 && rightMin != -1) {
            return min(leftMin, rightMin);
        }
        return max(leftMin, rightMin);
    }
};
