//二叉树的前序遍历，中序遍历，后序遍历

//迭代方法？
//莫里斯方法？
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

//前序遍历
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        Traversal(root,vec);
        return vec;
    }
    void Traversal(TreeNode * root,vector<int>& res)
    {
        if(root == nullptr)
            return;
        res.push_back(root->val);
        Traversal(root->left,res);
        Traversal(root->right,res);
    }
};

//中序遍历
class Solution2 {
public:
    void inorder(TreeNode * root,vector<int> & res)
    {
        if(!root)
            return;
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        inorder(root,vec);
        return vec;
    }
};

//后序遍历
class Solution3 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;
        Traversal(root,vec);
        return vec;
    }

    void Traversal(TreeNode * root,vector<int>& res)
    {
        if(root == nullptr)
            return;
        Traversal(root->left,res);
        Traversal(root->right,res);
        res.push_back(root->val);
    }
};
