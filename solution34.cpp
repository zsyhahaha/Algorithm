//¶þ²æÊ÷µÄ²ãÐò±éÀú

#include <iostream>
#include <vector>
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
