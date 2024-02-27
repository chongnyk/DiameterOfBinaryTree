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
    int heightOfBinaryTree(TreeNode* node){
        int lHeight, rHeight;
        lHeight = (node->left != nullptr) ? heightOfBinaryTree(node->left) : 0;
        rHeight = (node->right != nullptr) ? heightOfBinaryTree(node->right) : 0;
        return (lHeight > rHeight) ? lHeight + 1 : rHeight + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int lHeight, rHeight, lDiam, rDiam;
        lHeight = (root->left != nullptr) ? heightOfBinaryTree(root->left) : 0;
        rHeight = (root->right != nullptr) ? heightOfBinaryTree(root->right) : 0;
        cout << lHeight << ' ' << rHeight << '\n';
        lDiam = (root->left != nullptr) ? diameterOfBinaryTree(root->left) : 0;
        rDiam = (root->right != nullptr) ? diameterOfBinaryTree(root->right) : 0;
        return max({lHeight + rHeight, lDiam, rDiam}, [](int a, int b) {return a < b;});
    }
};
