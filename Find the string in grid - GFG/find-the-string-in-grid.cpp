// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    vector<vector<char>>s;
    string w;
public:
 bool diagonal(int i,int j,char g)
 {
     int k=0;
     while(i>=0&&j>=0&&i<s.size()&&j<s[0].size()&&k<w.size()&&w[k]==s[i][j])
     {
          //diagonal up-right i-- j++
	                 //diagonal right-down i++ j++
	                 //diagonal down-left i++ j--
	                 //diagonal left-up i-- j--
         switch(g)
         {
             case 'U'://upright
             {
               i--;
               j++;
               break;
             }
             case 'R':
             {
               i++;
               j++;
               break;
             }
             case 'D':
             {
                //  cout<<i<<" "<<j<<endl;
               i++;
               j--;
               break;
             }
             case 'L':
             {
               i--;
               j--;
               break;
             }
             
         }
         k++;
     }
     return  k==w.size();
 }
 bool Ndiagonal(int i,int j,int g)
 {
     int k=0;
     while(i>=0&&j>=0&&i<s.size()&&j<s[0].size()&&k<w.size()&&w[k]==s[i][j])
     {
          //diagonal up-right i-- j++
	                 //diagonal right-down i++ j++
	                 //diagonal down-left i++ j--
	                 //diagonal left-up i-- j--
         switch(g)
         {
             case 'U'://upright
             {
               i--;
               break;
             }
             case 'R':
             {
               j++;
               break;
             }
             case 'D':
             {
                 i++;
               break;
             }
             case 'L':
             {
               j--;
               break;
             }
             
         }
         k++;
     }
     return  k==w.size();
 }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    s=grid;
	    w=word;
	    vector<vector<int>> v;
	    int count=0;
	    for(int i=0;i<grid.size();i++)
	    {
	        for(int j=0;j<grid[0].size();j++)
	        {
	            if(grid[i][j]==word[0])
	             {
	                 if(diagonal(i,j,'U')||diagonal(i,j,'R')||diagonal(i,j,'D')||diagonal(i,j,'L')||Ndiagonal(i,j,'U')||Ndiagonal(i,j,'R')||Ndiagonal(i,j,'D')||Ndiagonal(i,j,'L'))
	                 v.push_back({i,j});
	             }
	        }
	    }
	    return v;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
	}
	return 0;
}  // } Driver Code Ends