class Solution {
public:
  bool check(int &m,string &s,int &k)
  {
     int a[256] = {0},i = 0, j = 0,words=0,count=0;
      // cout<<m<<" ";
            while(j<s.size())
            {
                a[s[j]]++;
                if(a[s[j]]==1)
                    words++;
                if(a[s[j]]==k)
                    count++;
                    if(j-i==m)
                    {
                        // if(m==2)
                        //     cout<<words<<" "<<count<<" "<<s[i]<<" "<<s[j]<<endl;
                        if(words==count)//we found
                            return 1;
                            
                            if (a[s[i]] == 1)
                                words--;
                            if(a[s[i]]==k)
                                count--;
                        a[s[i++]]--;
                    }
                    j++;
            }
            return 0;
  }
    int longestSubstring(string s, int k) {
        int l=k-1,h=s.size()-1;
        while(l<=h)
        {
            // int m = (l + h) / 2;
            if(check(h, s, k))
                return h+1;
            else
                h--;
            //     l = m + 1;
            // else h = m-1;
        }
        return 0;
    }
};