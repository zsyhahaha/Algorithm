//求二叉树的最大深度
#include <iostream>
#include <algorithm>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//自顶向下的递归
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        Depth(root,1);
        return maxdeep;
    }

    void Depth(TreeNode* root, int depth)
    {
        if(root == nullptr)
            return;
        if(root->left == nullptr && root->right == nullptr)
            maxdeep = max(maxdeep,depth);
        Depth(root->left,depth + 1);
        Depth(root->right,depth + 1);
    }

    int maxdeep = 0;
};

//自底向上的递归
class solution2
{
public:
    int maxDepth(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};