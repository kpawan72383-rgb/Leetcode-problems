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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> pos;
        int n = static_cast<int>(inorder.size());
        for (int i = 0; i < n; ++i) {
            pos[inorder[i]] = i;
        }
        return construct(preorder, 0, n - 1, inorder, 0, n - 1, pos);
    }
private:
    TreeNode* construct(const vector<int>& preorder, int preL, int preR,
                        const vector<int>& inorder, int inL, int inR,
                        const unordered_map<int, int>& pos) {
        if (preL > preR || inL > inR) {
            return nullptr;
        }
        int rootVal = preorder[preL];
        int inIdx = pos.at(rootVal);
        int leftCount = inIdx - inL;
        TreeNode* node = new TreeNode(rootVal);
        node->left = construct(preorder, preL + 1, preL + leftCount,
                               inorder, inL, inIdx - 1, pos);
        node->right = construct(preorder, preL + leftCount + 1, preR,
                                inorder, inIdx + 1, inR, pos);
        return node;
    }
};
