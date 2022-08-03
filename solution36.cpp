//判断二叉树是否对称
#include <iostream>
#include <queue>


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//递归方法
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root,root);
    }

    bool isMirror(TreeNode* t1,TreeNode* t2)
    {
        if(t1 == nullptr && t2 == nullptr)
            return true;
        if(t1 == nullptr || t2 == nullptr)
            return false;
        return (t1->val == t2->val) && isMirror(t1->right,t2->left) && isMirror(t1->left,t2->right);
    }
};

//迭代方法
class Solution2
{
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root,root);
    }

    bool isMirror(TreeNode* t1,TreeNode* t2)
    {
        queue<TreeNode*> que;
        que.push(t1);
        que.push(t2);
        while (!que.empty())
        {
            TreeNode * left = que.front();
            que.pop();
            TreeNode * right = que.front();
            que.pop();
            if(left == nullptr && right == nullptr)
                continue;
            if(left == nullptr || right == nullptr || (left->val != right->val))
                return false;
            que.push(left->left);
            que.push(right->right);

            que.push(left->right);
            que.push(right->left);
        }
        return true;
    }
};