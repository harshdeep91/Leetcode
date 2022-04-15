class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0,cows=0;
        unordered_map<int,int> m;
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i]==guess[i])//match bulls
                bulls++;
            else
                m[secret[i]]++;
        }
            
        for(int i=0;i<secret.size();i++)
        {
              if(secret[i]!=guess[i]&&m[guess[i]])
              {
                  // cout<<guess[i]<<" ";
                  cows++;
                  m[guess[i]]--;
              }
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};