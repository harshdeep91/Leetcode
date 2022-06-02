class Solution {
    vector<vector<int>> v;
    int count=1,r,c;
public:
    Solution(int m, int n) {
        v.resize(m,vector<int>(n,0));
        r=m,c=n;
    }
    
    vector<int> flip() {
        int x,y;
        do{
         x=(double)rand()/RAND_MAX*r;
         y=(double)rand()/RAND_MAX*c;
            // cout<<x<<" "<<y<<endl;
        }while(x==r||y==c||v[x][y]==count);
        v[x][y]=count;
        return {x,y};
        // return {0,0};
    }
    
    void reset() {
        count++;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */