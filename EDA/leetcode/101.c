#include <stdbool.h>
#include <stdlib.h>
   struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };
 
bool isSymmetric(struct TreeNode* root) {
    if (!root)
    {
        true;
    }
    if(!root->left && !root->right)
    {
        return false;
    }
    
}