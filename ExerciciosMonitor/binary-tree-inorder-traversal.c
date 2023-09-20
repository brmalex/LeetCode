/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void inorder(struct TreeNode* root, int * ret, int *i){
    if (root == NULL){
        return;
    }
    inorder(root->left, ret, i);
    ret[(*i)] = root->val;
    (*i)++;
    inorder(root->right, ret, i);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    int * temp = (int*)malloc(sizeof(int)*101);
    inorder(root, temp, returnSize);
    int * ret = (int*)malloc(sizeof(int)*(*returnSize));
    for(int i = 0; i < *returnSize; i++){
        ret[i] = temp[i];
    }
    free(temp);
    return ret;
}
