/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* intersect(Node* t1, Node* t2) {
         
        //apply or in two trees if t1,t2  have isleaf 1
        if(t1->isLeaf==1&&t2->isLeaf==1)
              return t1->val?t1:t2;
        if(t1->isLeaf==1)
            return t1->val?t1:t2;
        if(t2->isLeaf==1)
            return t2->val?t2:t1;
        
        Node * tmp=new Node();
        //go left and apply or
        tmp->topLeft=intersect(t1->topLeft,t2->topLeft);
        
        tmp->topRight=intersect(t1->topRight,t2->topRight);
        
        tmp->bottomLeft=intersect(t1->bottomLeft,t2->bottomLeft);
        
        tmp->bottomRight=intersect(t1->bottomRight,t2->bottomRight);
        
        //merge if they are leaves and have same val
    if(tmp->topLeft->isLeaf&&tmp->topRight->isLeaf&&tmp->bottomLeft->isLeaf&&tmp->bottomRight->isLeaf)//this means all leaf
      {
        if(tmp->topLeft->val&&tmp->topRight->val&&tmp->bottomLeft->val&&tmp->bottomRight->val)//this means all value 1
            return new Node(1,1);
        else if(tmp->topLeft->val==0&&tmp->topRight->val==0&&tmp->bottomLeft->val==0&&tmp->bottomRight->val==0)//all value 0  
            return new Node(0,1);
      }
        tmp->val=0;
        tmp->isLeaf=0;
        return tmp;
    }
};