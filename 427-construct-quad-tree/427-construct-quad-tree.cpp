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
    Node* solve(int x,int y,int n,vector<vector<int>>& grid)
    {
        // cout<<x<<" "<<y<<" "<<n<<endl;
        if(x==n&&y==n)//means single value
        {
            return new Node(grid[x][y],1);
        }
        else //divide into 4 parts
        {
            //check if they have same values
            int val=grid[x][y],i=0,j=0;
            for(int i=0;i<=n;i++)
            {
                for(int j=0;j<=n;j++)
                {
                     // cout<<" ("<<i+x<<","<<j+y<<") "<<endl;
                    if(grid[i+x][j+y]!=val)//we havent got same values call 4 times
                    {
                        // cout<<grid[i+x][j+y]<<" "<<val<<endl;
                        Node *t=new Node(1,0);
                        //topleft
                        t->topLeft=solve(x,y,n/2,grid);
                        //topRight
                        t->topRight=solve(x,y+n/2+1,n/2,grid);
                        //bottomLeft
                        t->bottomLeft=solve(x+n/2+1,y,n/2,grid);
                        //bottomRight
                        t->bottomRight=solve(x+n/2+1,y+n/2+1,n/2,grid);
                        return t;
                    }
                }
            }
                return new Node(grid[x][y],1);
        }
        
    }
    Node* construct(vector<vector<int>>& grid) {
        //divide grid into 4 parts
        //check if they have same values return node isleaf=1,val=values
        //if not divide again 4 parts set call set individually
        //base case if when size==1
        return solve(0,0,grid.size()-1,grid);
    }
};