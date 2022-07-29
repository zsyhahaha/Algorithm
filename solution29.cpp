//����������ͨͼ��һ���ڵ�����ã����㷵�ظ�ͼ�� �������¡����
//ͼ�е�ÿ���ڵ㶼��������ֵ val��int�� �����ھӵ��б�list[Node]����
#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

//�ݹ�ʵ��������ȱ���
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

        // ����ýڵ��Ѿ������ʹ��ˣ���ֱ�Ӵӹ�ϣ����ȡ����Ӧ�Ŀ�¡�ڵ㷵��
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        // ��¡�ڵ㣬ע�⵽Ϊ��������ǲ����¡�����ھӵ��б�
        Node* cloneNode = new Node(node->val);
        // ��ϣ��洢
        visited[node] = cloneNode;

        // �����ýڵ���ھӲ����¿�¡�ڵ���ھ��б�
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