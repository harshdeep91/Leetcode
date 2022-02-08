// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool issafe(int i,int j,int k,vector<vector<char> > &mat, string &target)
    {
        if(i<mat.size()&&j<mat[0].size()&&i>=0&&j>=0&&mat[i][j]==target[k])
        return 1;
        return 0;
    }
    void solve(int i,int j,int k,vector<vector<char> > &mat, string &target,int &count){
        // cout<<i<<" "<<j<<" "<<k<<endl;
        if(k==target.size()){
            count++;
            return ;
        }
        if(issafe(i,j+1,k,mat,target))//right
        {
            char t=mat[i][j];
            mat[i][j]='0';
            solve(i,j+1,k+1,mat,target,count);
            mat[i][j]=t;
        }
        if(issafe(i+1,j,k,mat,target))//down
        {char t=mat[i][j];
            mat[i][j]='0';
            solve(i+1,j,k+1,mat,target,count);
            mat[i][j]=t;
        }
        if(issafe(i,j-1,k,mat,target))//left
        {
            char t=mat[i][j];
            mat[i][j]='0';
            solve(i,j-1,k+1,mat,target,count);
            mat[i][j]=t;
        }
        if(issafe(i-1,j,k,mat,target))//up
        {
            char t=mat[i][j];
            mat[i][j]='0';
            solve(i-1,j,k+1,mat,target,count);
            mat[i][j]=t;
        }
        
    }
    int findOccurrence(vector<vector<char> > &mat, string target){
         int count=0,k=0;
         for(int i=0;i<mat.size();i++)
         {
             for(int j=0;j<mat[0].size();j++)
             {
                 
                 if(issafe(i,j,0,mat,target))
                 {
                    //  cout<<"called"<<endl;
                     solve(i,j,1,mat,target,count);
                 }
             }
         }
        return count;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}
  // } Driver Code Ends