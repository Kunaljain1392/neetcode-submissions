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
    bool sameTree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL && subRoot == NULL) {
            return true;
        }
        if(root == NULL || subRoot == NULL) {
            return false;
        }
        if(root->val != subRoot->val) {
            return false;
        }
        bool left = sameTree(root->left,subRoot->left);
        bool right = sameTree(root->right,subRoot->right);

        return left && right;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root ==  NULL) {
            return false;
        }
        if(subRoot == NULL) {
            return true;
        }
        if(sameTree(root,subRoot)) {
            return true;
        }

        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};
