#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int solve(TreeNode *curr, TreeNode *parent)
{
    if (curr == NULL)
    {
        return 0;
    }
    if (curr->left == NULL && curr->right == NULL)
    {
        if (parent != NULL && parent->left == curr)
        {
            return curr->val;
        }
    }
    int left = solve(curr->left, curr);
    int right = solve(curr->right, curr);
    return left + right;
}

int polve(TreeNode *curr, bool isLeft)
{
    if (curr == NULL)
    {
        return 0;
    }
    if (curr->left == NULL && curr->right == NULL && isLeft == true)
    {
        return curr->val;
    }
    return polve(curr->left, true) + polve(curr->right, false);
}

int sumOfLeftLeaves(TreeNode *root)
{
    // return solve(root, NULL);
    return polve(root, false);
}
