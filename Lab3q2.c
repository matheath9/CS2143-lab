#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to recursively perform in-order traversal
void helperInOrderTraversal(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) {
        return;
    }
    // Traverse left subtree
    helperInOrderTraversal(root->left, result, index);
    // Store the current node's value
    result[(*index)++] = root->val;
    // Traverse right subtree
    helperInOrderTraversal(root->right, result, index);
}

// In-order traversal function
int* inOrderTraversal(struct TreeNode* root, int* returnSize) {
    // Allocate memory for the result array (assuming a maximum size)
    int* result = (int*)malloc(1000 * sizeof(int)); // Adjust size if needed
    *returnSize = 0;
    int index = 0;

    // Perform in-order traversal
    helperInOrderTraversal(root, result, &index);

    *returnSize = index;
    return result;
}