/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void postorderTraversal(struct Node* root, int* ret, int* i){
    if(root == NULL){
        return;
    }
    for(int j = 0; j < root->numChildren; j++){
        postorderTraversal(root->children[j], ret, i);
    }
    ret[(*i)] = root->val;
    (*i)++;
}

int* postorder(struct Node* root, int* returnSize) {
    int * ret;
    *returnSize = 0;  
    int * temp = (int *)malloc(sizeof(int)*10001);
    postorderTraversal(root, temp, returnSize);
    ret = (int *)malloc(sizeof(int)*(*returnSize));
    for (int i = 0; i < *returnSize; i++){
        ret[i] = temp[i];
    }
    return ret;
}
