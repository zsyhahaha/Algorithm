//给你无向连通图中一个节点的引用，请你返回该图的 深拷贝（克隆）。
//图中的每个节点都包含它的值 val（int） 和其邻居的列表（list[Node]）。
#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

//递归实现深度优先遍历
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    unordered_map<Node*, Node*> visited;
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return node;
        }

        // 如果该节点已经被访问过了，则直接从哈希表中取出对应的克隆节点返回
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        // 克隆节点，注意到为了深拷贝我们不会克隆它的邻居的列表
        Node* cloneNode = new Node(node->val);
        // 哈希表存储
        visited[node] = cloneNode;

        // 遍历该节点的邻居并更新克隆节点的邻居列表
        for (auto& neighbor: node->neighbors) {
            cloneNode->neighbors.emplace_back(cloneGraph(neighbor));
        }
        return cloneNode;
    }
};

int main()
{
    Solution s;
    Node * adjust1 = new Node(1);
    Node * adjust2 = new Node(2);
    Node * adjust3 = new Node(3);
    Node * adjust4 = new Node(4);
    adjust1->neighbors = {adjust2,adjust4};
    adjust2->neighbors = {adjust1,adjust3};
    adjust3->neighbors = {adjust2,adjust4};
    adjust4->neighbors = {adjust1,adjust3};

    Node * adjust5 = s.cloneGraph(adjust1);
}