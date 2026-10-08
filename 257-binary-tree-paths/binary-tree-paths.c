#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void searchBT(struct TreeNode* root, char* path,
              char** answer, int* returnSize) {

    if (root == NULL) {
        return;
    }

    char currentPath[1000];

    // Add current node to path
    if (strlen(path) == 0) {
        sprintf(currentPath, "%d", root->val);
    } else {
        sprintf(currentPath, "%s->%d", path, root->val);
    }

    // Leaf node
    if (root->left == NULL && root->right == NULL) {

        answer[*returnSize] = malloc(strlen(currentPath) + 1);

        strcpy(answer[*returnSize], currentPath);

        (*returnSize)++;

        return;
    }

    // Left subtree
    if (root->left != NULL) {
        searchBT(root->left, currentPath, answer, returnSize);
    }

    // Right subtree
    if (root->right != NULL) {
        searchBT(root->right, currentPath, answer, returnSize);
    }
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {

    *returnSize = 0;

    char** answer = malloc(100 * sizeof(char*));

    if (root != NULL) {
        char path[1000] = "";
        searchBT(root, path, answer, returnSize);
    }

    return answer;
}