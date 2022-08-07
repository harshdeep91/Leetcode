class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        if(b>c)swap(b,c);
        if(a>b)swap(a,b);
        if(b>c)swap(b,c);
        // cout<<a<<" "<<b<<" "<<c<<endl;
        int x= b-a-1,y=c-b-1;
        int mi=min((bool)x+(bool)y,(x==1||y==1)?1:2);
        return {mi,x+y};
    }
};