class Solution {
    unordered_map<string,double> m;
    int count=0;
public:
    double solve(int a,int b)
    {
        // cout<<a<<" "<<b<<endl;
        count++;
        // cout<<a<<" "<<b<<endl;
            if(a<=0)//a and b both becomes empty or a empty
                return b<=0?0.5:1;
              if(b<=0)return 0; //b only empty
        // cout<<"pass"<<endl;
        string key=to_string(a)+"*"+to_string(b);
        // cout<<key<<endl;
        if(m.find(key)!=m.end())return m[key];
        double x=0;
        // first turn 
        x+= solve(a-25*4,b-25*0);
        // second turn 
        x+= solve(a-25*3,b-25*1);
        // third turn 
        x+= solve(a-25*2,b-25*2);
        // fourth turn 
        x+= solve(a-25*1,b-25*3);
        return m[key]=(0.25)*x;
    }
    double soupServings(int n) {
        //every turn 0.25 is multiplied
        //check every turn 
        // for(int i=0;i<)
        //sum could be -25,-75,-50,-100
        if(n>8000)return 1;
        // cout<<count<<endl;
        return solve(n,n);
    }
};