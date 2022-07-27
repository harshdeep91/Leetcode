class Solution {
public:
    string solve(int a,int b,char aa,char bb)
    {
        int val_a= a/2,val_b=b/2,split=b%2,extra_a=a%2;
        //we need vala-1 b's
        //if(val_b<val_a-1)split them into 2
        //if(val_b>val_a-1)split avoid split
         string ans;
        if(a==1)
        {
            ans.push_back(aa);
            while(b--)ans.push_back(bb);
            return ans;
        }
         while(val_b+split<val_a-1+extra_a)
         {
             split+=2;
             val_b--;
         }
        // cout<<val_b<<" "<<split<<" "<<val_a-1<<endl;
        //first put a then b and 
        while(ans.size()<a+b)
        {
            if(val_a)
                ans.push_back(aa),ans.push_back(aa),val_a--;
            else if(extra_a)
                ans.push_back(aa),extra_a--;
            if(val_b)
                ans.push_back(bb),ans.push_back(bb),val_b--;
            else if(split)
                ans.push_back(bb),split--;
        }
        
        return ans;
    }
    string strWithout3a3b(int a, int b) {
        //see the recursion first
        //we can simply put 2 a first
        //then check how many min b we need
        // it is simply value-1
        //if b is greater put them in 2 digits
        return  (a<b)?solve(b,a,'b','a'):solve(a,b,'a','b');
        
    }
};