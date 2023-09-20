/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* ret;
struct TreeNode* next;
void inorder(struct TreeNode* root){
    if (root == NULL){
        return;
    }
    inorder(root->left);
    if(ret == NULL){
        ret = root;
    }
    else{
        next->right = root;
    }
    next = root;
    next->left = NULL;
    inorder(root->right);
}

struct TreeNode* increasingBST(struct TreeNode* root){
    ret = NULL;
    next = NULL;
    inorder(root);
    return ret;
}
