class Solution {
// unordered_map<
vector<vector<string>> dp;
string ans;
public:
string solve(int a,int b,string s)
{
// cout<<a<<" "<<b<<endl;
if(a+b==0)
{
ans=s;
return "1";
}
//choose a
if(dp[a][b]!="")return dp[a][b];
if(ans.empty()&&a>0&&(s[s.size()-2]!='a')
solve(a-1,b,s+"a");
//choose b
if(ans.empty()&&b>0&&(s[s.size()-2]!='b'||s[s.size()-1]!='b'))
solve(a,b-1,s+"b");
return dp[a][b]="1";
}
string strWithout3a3b(int a, int b) {
//we can either use 1a or 2a
// 1a,2a,1b,2b
//2a only when prev digit is b
//2b same
//1a only when last 2 digit is not a
dp.resize(a+1,vector<string>(b+1,""));
solve(a,b,"  ");
ans.erase(ans.begin(),ans.begin()+2);
return ans;
}
};