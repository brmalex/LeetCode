/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int findSecondMinimumValue(struct TreeNode* root){
    int smallest;
    if (root->left != NULL && root->right != NULL){
        if (root->left->val < root->right->val){
            int smallest = root->right->val;
            return findSmallestValue(root->left, smallest);
        }
        else if (root->left->val > root->right->val){
            int smallest = root->left->val;
            return findSmallestValue(root->right, smallest);
        }
        else {
            return -1;
        }
    }
    else {
        return -1;
    }
}

int findSmallestValue(struct TreeNode* root, int smallest){
    if (root->left != NULL && root->right != NULL){
        if (root->left->val < root->right->val){
            if (smallest >= root->right->val && root->right->val != root->val){
                smallest = root->right->val;
            }
            return findSmallestValue(root->left, smallest);
        }
        else if (root->left->val > root->right->val){
            if (smallest >= root->left->val && root->left->val != root->val){
                smallest = root->left->val;
            }
            return findSmallestValue(root->right, smallest);
        }
        else{
            return findSmallestValue(root->right, smallest);
            return findSmallestValue(root->left, smallest);
        }
    }
    return smallest;
}
