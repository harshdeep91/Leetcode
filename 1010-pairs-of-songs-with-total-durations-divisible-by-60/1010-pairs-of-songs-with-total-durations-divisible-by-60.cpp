class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        //get the numbers in divisible 60 first
        for(int i=0;i<time.size();i++)
            time[i]%=60;
        //now put them in map
        int a[60]={0};
        for(int i=0;i<time.size();i++)a[time[i]]++;
        int i=0,req;
        
        long long int count=0;
        while(i<time.size())
        {
            req=abs(time[i]-60)%60;
            if(a[req])
                count+= (req==time[i]?((long long int)a[req]*(a[req]-1))/2:(long long int)a[time[i]]*a[req]);
            a[time[i]]=0,a[req]=0;
            // cout<<i<<" "<<count<<" "<<time[i]<<" "<<req<<endl;
            i++;
            
        }
        return count;
    }
};