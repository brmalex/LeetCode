/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void invert(struct TreeNode* root, struct TreeNode* ret){
    if (root == NULL){
        return;
    }
    ret->right = root->right;
    ret->left = root->left;
    if (root->left != NULL){
        invert(root->left, ret->left);
    }
    if (root->right != NULL){
        invert(root->right, ret->right);
    }
    struct TreeNode* temp;
    temp = ret->right;
    ret->right = ret->left;
    ret->left = temp;
}

struct TreeNode* invertTree(struct TreeNode* root){
    struct TreeNode* ret = NULL;
    if (root == NULL){
        return ret;
    }
    ret = malloc(sizeof(struct TreeNode));
    ret->val = root->val;
    invert(root, ret);
    return ret;
}
