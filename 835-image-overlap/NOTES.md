class Solution {
int mx=0,n;
public:
vector<vector<int>> shift_L(vector<vector<int>> img)
{
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
img[i][j]=j+1<n?img[i][j+1]:0;
return img;
}
vector<vector<int>> shift_R(vector<vector<int>> img)
{
for(int i=0;i<n;i++)
for(int j=n-1;j>=0;j++)
img[i][j]=j-1>=0?img[i][j-1]:0;
return img;
}
vector<vector<int>> shift_D(vector<vector<int>> img)
{
for(int i=0;i<n;i++)
for(int j=n-1;j>=0;j++)
img[j][i]=j-1>=0?img[j-1][i]:0;
return img;
}
vector<vector<int>> shift_U(vector<vector<int>> img)
{