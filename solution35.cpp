//���������������
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

//�Զ����µĵݹ�
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

//�Ե����ϵĵݹ�
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