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
    unordered_map<int, int> mp;
    int postIdx;
    TreeNode* build(const vector<int>& inorder, const vector<int>& postorder, int inLeft, int inRight) {
        if (inLeft > inRight) {
            return nullptr;
        }
        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);
        int mid = mp[rootVal];
        root->right = build(inorder, postorder, mid + 1, inRight);
        root->left = build(inorder, postorder, inLeft, mid - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < static_cast<int>(inorder.size()); ++i) {
            mp[inorder[i]] = i;
        }
        postIdx = static_cast<int>(postorder.size()) - 1;
        return build(inorder, postorder, 0, static_cast<int>(inorder.size()) - 1);
    }
};
