/*
// Definition for a Node.
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
*/

class Solution {
public:
    void dfs(Node *p,unordered_map<int,Node*> &m)
    {
        Node *copy=new Node(p->val);
        m[p->val]=copy;
        
        for(auto x:p->neighbors)
        {
            if(!m[x->val])
            {
                dfs(x,m);
            }
            copy->neighbors.push_back(m[x->val]);
        }
    }
    Node* cloneGraph(Node* node) {
        unordered_map<int,Node*> m;
        if(!node)
            return node;
         dfs(node,m);
        return m[1];
    }
};