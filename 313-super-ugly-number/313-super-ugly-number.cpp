struct node{
  int product,index,value;  
};
bool operator<(const node& p1, const node& p2)
{
    return p1.product > p2.product;
}
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n <= 0) return false;  
        if(n == 1) return true;
        
          priority_queue<node> q;
        for(int i=0;i<primes.size();i++)
        {
            q.push({primes[i],0,primes[i]});
        
        }
        vector<int> k(n);
        k[0] = 1;
        int i=1;
        while(!q.empty()&&i<n)
        {
            node s=q.top();
            q.pop();
            // cout<<s.product<<" "<<s.index<<" "<<s.value<<" ---- ";
            k[i]=s.product;
            if(k[i-1]==k[i])
                i--;
            s.index++;
            long long int t=k[s.index];
            t*=s.value;
            if(t>INT_MAX)
                continue;
            s.product=t;
                q.push(s);
            
            // cout<<s.product<<" "<<s.index<<" "<<s.value<<"---"<<k[i]<<endl;
            i++;
        }
        return k[n-1];
    }
};