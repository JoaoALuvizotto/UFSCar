#include <stdbool.h>
#include <stdio.h>

 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

int maxDepth(struct TreeNode* root) {
    if (!root)
    {
        return 0;
    }
    
    int alturaEsq = 1 + maxDepth(root->left);
    int alturaDir = 1 + maxDepth(root->right);

    if (alturaEsq > alturaDir)
        return alturaEsq;
    else
        return alturaDir;
}

bool isBalanced(struct TreeNode* root) {
    
    if (!root)
    {
        return true;
    }

    int alturaEsq = maxDepth(root->left);
    int alturaDir = maxDepth(root->right);

    int diff = alturaEsq - alturaDir;

    if (diff == 0 || diff == 1 || diff == -1){
        return isBalanced(root->left) && isBalanced(root->right);
    }

    return false; 
}