
class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetlen) {
         sort(tiles.begin(),tiles.end());
        // for(auto x:tiles)
        //     cout<<x[0]<<" "<<x[1]<<"\n";
    int first=tiles[0][0],last=first+carpetlen-1,n=tiles.size(),prefixsum[n],counter,useless=0,ans=0,i=0; prefixsum[0]=0;
    vector<pair<int, int>> v;
    v.push_back({tiles[0][0], tiles[0][1]});
    for (int i = 1; i < n; i++)
    {
        prefixsum[i] = prefixsum[i - 1] + (tiles[i][0] - tiles[i - 1][1] - 1);
        v.push_back({tiles[i][0], tiles[i][1]});
    }
        // cout<<n;
    if(carpetlen>tiles[n-1][1]||last>=tiles[n-1][1])
    return tiles[n-1][1]-tiles[0][0]+1-prefixsum[n-1];
    if(n==1)
        return min(carpetlen, tiles[0][1] - tiles[0][0] + 1);
    while (last <= tiles[n - 1][1])
    {
        pair<int, int> k = {last, INT_MIN};
        auto it = upper_bound(v.begin(), v.end(),k) - v.begin();
        if(it==n||last!=v[it].first)
            it--;
        // cout<<it<<" ";
            useless = prefixsum[it] - prefixsum[i];
            last = min(last, v[it].second);
            counter = last - first + 1 - useless;
            ans = max(ans, counter);
        i++;
        if(i==n)return ans;
            first=v[i].first;
            last = first + carpetlen - 1;
        // cout<<last<<endl;
    }
    return ans;
    }
};
