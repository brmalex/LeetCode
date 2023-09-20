/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int traverse(struct TreeNode* root, int i){
    int a = i, b = i;
    if (root->left != NULL){
       a = traverse(root->left, i+1);
    }
    if (root->right != NULL){
       b = traverse(root->right, i+1);
    }
    if (a > b){
        i = a;
    }
    else{
        i = b;
    }
    return i;
}

int maxDepth(struct TreeNode* root){
    if(root == NULL){
        return 0;
    }
    int i = 1;
    int a = i, b = i;
    if (root->left != NULL){
       a = traverse(root->left, i+1);
    }
    if (root->right != NULL){
       b = traverse(root->right, i+1);
    }
    if (a > b){
        i = a;
    }
    else{
        i = b;
    }
    return i;
}
