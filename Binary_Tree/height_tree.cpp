int height(Node* root) {
    if (root == NULL) {
        return 0;  // Empty tree has height 0
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}
