#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode * left;
    struct TreeNode * right;
};

int findSecondMinimumValue( struct TreeNode * root);
int findSmallestValue( struct TreeNode * root, int smallest );
struct TreeNode * criarNodo( int val );

int main(){
    struct TreeNode * root = criarNodo( 2 );
    root->left = criarNodo( 2 );
    root->right = criarNodo( 5 );
    root->right->left = criarNodo( 5 );
    root->right->right = criarNodo( 7 );
    printf( "%d", findSecondMinimumValue( root ) );
    free( root->left );
    free( root->right->left );
    free( root->right->right );
    free( root->right );
    free( root );
}

struct TreeNode * criarNodo( int val ){
    struct TreeNode * ret = ( struct TreeNode * ) malloc ( sizeof ( struct TreeNode ) );
    ret->val = val;
    ret->left = NULL;
    ret->right = NULL;
    return ret;
}

int findSecondMinimumValue( struct TreeNode * root ) {
    int s1;
    int s2;
    if ( ( root->left != NULL ) && ( root->right != NULL ) ) {
        if ( root->left->val < root->right->val ) {
            int s1 = root->right->val;
            return findSmallestValue( root->left, s1 );
        } else if ( root->left->val > root->right->val ) {
            int s1 = root->left->val;
            return findSmallestValue( root->right, s1 );
        } else {
            s1 = findSecondMinimumValue( root->right );
            s2 = findSecondMinimumValue( root->left );
            if( ( s1 < s2 ) && ( s1 != -1 ) ) {
                return s1;
            } else if ( ( s2 < s1 ) && ( s2 != -1 ) ) {
                return s2;
            } else {
                return -1;
            }
        }
    } else {
        return -1;
    }
}

int findSmallestValue( struct TreeNode * root, int smallest ) {
    int s1, s2;
    if ( ( root->left != NULL ) && ( root->right != NULL ) ) {
        if ( root->left->val < root->right->val ) {
            if ( ( smallest >= root->right->val ) && ( root->right->val != root->val ) ) {
                smallest = root->right->val;
            }
            return findSmallestValue( root->left, smallest );
        } else if ( root->left->val > root->right->val ) {
            if ( ( smallest >= root->left->val ) && ( root->left->val != root->val ) ) {
                smallest = root->left->val;
            }
            return findSmallestValue( root->right, smallest );
        } else {
            s1 = findSmallestValue( root->right, smallest );
            s2 = findSmallestValue( root->left, smallest );
            if ( s1 < s2 ) {
                return s1;
            } else {
                return s2;
            }
        }
    }
    return smallest;
}
