/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSameTree(TreeNode* A, TreeNode* B) {

    if (A == NULL and B == NULL) {
        return 1;
    } else if (A == NULL or B == NULL) {
        return 0;
    }

    if (A -> val != B -> val) {
        return 0;
    }
    int s1  = isSameTree(A->left, B->left);
    int s2  =  isSameTree(A->right, B->right);

    return s1 and s2;
}
