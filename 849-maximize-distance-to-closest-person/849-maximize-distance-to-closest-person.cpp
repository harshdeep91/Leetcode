class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> left=seats,right=seats;
        int mi=0;
        //take 0 as -1 
        //dis from left
        for(int i=0;i<seats.size();i++)
            if(seats[i]==0)
                left[i]=(i>0?left[i-1]:0)-1;
        mi=left.back();//edge case
        // for(int i=0;i<seats.size();i++)
        //     cout<<left[i]<<" ";
        // cout<<endl;
        
        for(int i=seats.size()-1;i>=0;i--)
            if(seats[i]==0)
            {
                right[i]=(i+1<seats.size()?right[i+1]:0)-1;
                left[i]=max(left[i],right[i]);
            }
         mi=min(right.front(),mi);//edge case
        // for(int i=0;i<seats.size();i++)
        //     cout<<right[i]<<" ";
        // cout<<endl;
        for(int i=0;i<seats.size();i++)
            mi=min(left[i],mi);
        // cout<<mi<<" ";
        return 1-mi;
    }
};