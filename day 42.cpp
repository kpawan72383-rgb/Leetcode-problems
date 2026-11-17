class Solution {
    bool isSymmetricHelp(TreeNode* leftRoot, TreeNode* rightRoot) {
        if (!leftRoot && !rightRoot) return true;
        if (!leftRoot || !rightRoot) return false;
        return (leftRoot->val == rightRoot->val) && 
               isSymmetricHelp(leftRoot->left, rightRoot->right) && 
               isSymmetricHelp(leftRoot->right, rightRoot->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isSymmetricHelp(root->left, root->right);
    }
};
