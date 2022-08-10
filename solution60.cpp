//����һ���������ĸ��ڵ� root ���ж����Ƿ���һ����Ч�Ķ�����������
//��Ч �����������������£�
//  �ڵ��������ֻ���� С�� ��ǰ�ڵ������
//  �ڵ��������ֻ���� ���� ��ǰ�ڵ������
//  �������������������������Ҳ�Ƕ�����������
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stack;
        long long inorder = (long long)INT_MIN - 1;

        while (!stack.empty() || root != nullptr) {
            while (root != nullptr) {
                stack.push(root);
                root = root -> left;
            }
            root = stack.top();
            stack.pop();
            // �����������õ��Ľڵ��ֵС�ڵ���ǰһ�� inorder��˵�����Ƕ���������
            if (root -> val <= inorder) {
                return false;
            }
            inorder = root -> val;
            root = root -> right;
        }
        return true;
    }
};

int main()
{
    TreeNode * tree1 = new TreeNode(2);
    TreeNode * tree2 = new TreeNode(1);
    TreeNode * tree3 = new TreeNode(3);
    tree2->left = tree1;
    tree2->right = tree3;
    Solution s;
    s.isValidBST(tree2);
    return 0;
}

