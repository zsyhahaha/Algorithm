# 8.1

> 二叉树

1. 二叉树的前序遍历、中序遍历和后序遍历

```c++
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
```

```c++
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
```

```c++
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
```

递归方式比较简单，需要考虑如何使用迭代方法来实现

2. 二叉树的层序遍历

```c++
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root)
            return ret;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
            int currentLevelSize = que.size();
            ret.push_back(vector<int>());
            //每次循环该层的元素，将其孩子结点入队，该层元素写入数组
            for(int i = 0; i < currentLevelSize; ++i)
            {
                auto node = que.front();
                que.pop();
                ret.back().push_back(node->val);
                if(node->left)
                    que.push(node->left);
                if(node->right)
                    que.push(node->right);
            }
        }
        return ret;
    }
};
```

使用队列来实现广度优先搜索

3. 求二叉树的最大深度（自顶向下和自底向上）
* 自顶向下的方法
```c++
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
```
* 自底向上的方法（较简单）
```c++
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
```
4. 二叉树的递归
   1. 判断二叉树是否对称
   2. 二叉树路径总和

> 哈希集合与哈希映射

1. 设计哈希集合与哈希映射


