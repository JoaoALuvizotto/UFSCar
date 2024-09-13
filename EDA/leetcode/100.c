#include <stdbool.h>
#include <stdio.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };
 
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (!p && !q)
    {
        return true;
    }
    if (!p || !q)
    {
        return false;
    }

    if (p->val == q->val)
    {
        bool treeleft = isSameTree(p->left, q->left);
        bool treeright = isSameTree(p->right, q->right);
        return treeleft && treeright;
    }
    return false;
    
}