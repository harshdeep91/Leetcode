class Solution {
public:
    int maxProduct(vector<string>& words) {
         int n = words.size();
        int cnt[n];
        memset(cnt, 0, sizeof(cnt));
        
        for (int i=0; i<words.size(); i++) {
            for(char ch: words[i]) {
                cnt[i] = cnt[i] | (1<< (ch-'a'));
            }
        }
        
        int max_len = 0;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if (cnt[i] & cnt[j])
                    continue;
                int tmp = words[i].size() * words[j].size();
                
                if(max_len < tmp) max_len = tmp;
            
            }
        }
        return max_len;
    }
};