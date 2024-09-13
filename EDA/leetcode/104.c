#include <stdbool.h>
#include <stdlib.h>
   struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };
 
int maxDepth(struct TreeNode* root) 
{   int tamEsq, tamDir;
    if (!root)
    {
        return 0;
    }

    tamEsq = 1 + maxDepth(root->left);
    tamDir = 1 + maxDepth(root->right);

    if (tamEsq > tamDir)
    {
        return tamEsq;
    }
    return tamDir;
    

}