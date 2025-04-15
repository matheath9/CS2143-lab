#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to recursively perform preorder traversal
void helperPreorderTraversal(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) {
        return;
    }
    // Store the current node's value
    result[(*index)++] = root->val;
    // Traverse left subtree
    helperPreorderTraversal(root->left, result, index);
    // Traverse right subtree
    helperPreorderTraversal(root->right, result, index);
}

// Preorder traversal function
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    // Allocate memory for the result array (assuming a maximum size)
    int* result = (int*)malloc(1000 * sizeof(int)); // Adjust size if needed
    *returnSize = 0;
    int index = 0;

    // Perform preorder traversal
    helperPreorderTraversal(root, result, &index);

    *returnSize = index;
    return result;
}