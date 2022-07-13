class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int a[26]={0};
        vector<string> ans;
        for(auto x:words2) //try the different words count 
        {
            int b[26]={0};
            for(auto y:x)
                b[y-'a']++;
            for(int i=0;i<26;i++)
                a[i]=max(a[i],b[i]);
        }
        //now check if this exist or not
        for(auto x:words1) //try the different words count 
        {
            int b[26]={0},i=0;
            for(auto y:x)
                b[y-'a']++;
            //b should satisfy the condition of a means it should not be minimum
            while(i<26&&a[i]<=b[i])i++;
                if(i==26)
                    ans.push_back(x);
                
        }
        return ans;
    }
};