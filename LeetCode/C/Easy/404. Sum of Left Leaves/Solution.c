/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int helper(struct TreeNode* root, bool isLeft) {
    if (root->left == NULL && root->right == NULL && isLeft) {
        return root->val;
    }

    int sum = 0;

    if (root->left != NULL) {
        sum += helper(root->left, true);
    }

    if (root->right != NULL) {
        sum += helper(root->right, false);
    }

    return sum;
}

int sumOfLeftLeaves(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    return helper(root, false);
}