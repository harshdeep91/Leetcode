class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int len[26]={0}, i = 0, n = p.size();
        for(int j=0;j<n;j++)
            if(j>i && p[j-1]+1!=p[j] && p[j-1]-p[j]!=25) {
                for(int k=i;k<min(j,i+26);k++) len[p[k]-'a'] = max(len[p[k]-'a'],j-k);
                i=j--;
            }
        for(int k=i;k<min(n,i+26);k++) len[p[k]-'a'] = max(len[p[k]-'a'],n-k);
        return accumulate(len,len+26,0);
    }
};
    
//     int findSubstringInWraproundString(string a) {
//         int c=0,i=0,j=0,m[256]={0};
//         while(j<a.size())
//         {
//              i=j;
//             flag=0;
//              while(j<a.size()&&(i==j||(a[j]-a[j-1]==1)||(a[j]=='a'&&a[j-1]=='z')))
//                 { 
//                      m[a[j]]++;
//                      if(m[a[j]]==1)//first time i to j puri count hogi i-j i+1-j
//                         c+= (j-i+1);
//                      j++;
//                  }
//         }
//                    return c;
//     }
// };
//problems is we cant simply count and check like here
//"abcdefghijklmnopqrstuvwxyza" this test case will fail