# 8.1

> ������

1. ��������ǰ���������������ͺ������

```c++
  //ǰ�����
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
//�������
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
//�������
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

�ݹ鷽ʽ�Ƚϼ򵥣���Ҫ�������ʹ�õ���������ʵ��

2. �������Ĳ������

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
            //ÿ��ѭ���ò��Ԫ�أ����亢�ӽ����ӣ��ò�Ԫ��д������
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

ʹ�ö�����ʵ�ֹ����������

3. ��������������ȣ��Զ����º��Ե����ϣ�
* �Զ����µķ���
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
* �Ե����ϵķ������ϼ򵥣�
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
4. �������ĵݹ�
   1. �ж϶������Ƿ�Գ�
   2. ������·���ܺ�

> ��ϣ�������ϣӳ��

1. ��ƹ�ϣ�������ϣӳ��


