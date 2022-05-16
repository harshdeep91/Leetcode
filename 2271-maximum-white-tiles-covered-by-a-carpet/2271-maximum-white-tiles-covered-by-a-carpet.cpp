/*Intuition: it's always better to place a carpet at the beginning of a white tile range. The reason is, if you shift a carpet one tile forward, you might cover another white tile, but you definitely uncover the previous white tile.

So, we sort tile ranges, and check how many white tiles we can cover, starting from the beginning of each range.

To avoid TLE, we "drag" our carpet over ranges using a sliding window. Applying sliding window is a bit tricky here:

We track the current placement of the carpet (tiles[j][0]).
When we can cover tiles[i], we add those tiles to cover.
	Otherwise, we partially cover tiles[i]
	We remove tiles[j] from cover.
	We move the placement of the carpet (++j)
*/
class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& t, int len) 
	{
	    int res = 0, i = 0, cover = 0;//cover is length of white tiles covered by carpet in current window
	    sort(t.begin(), t.end());
	    for (int j = 0; j < t.size();)//carpet starts from j and end at i
	    {
	        if (j == i || t[i][0] + len > t[j][1]) //carpet starting from j is exceeding this window(as this window is ending at i)
			{
	            cover += t[j][1] - t[j][0] + 1;//this window is being extended to cover this patch also
	            res = max(res, cover);
	            ++j;//let this window try to cover next patch by expanding its right end
	        }
	        else//carpet starting from jth patch is not able to cover this whole patch at i 
			{
	            res = max(res, cover + max(0, t[i][0] + len - t[j][0]));
	            					/* Partial length covered by 
	            					   carpet in this patch
	            					*/
	            cover -= (t[i][1] - t[i][0] + 1);//window will slide towards right hence remove the contribution of cover given by left most 
	            								//patch of current window. 
	            ++i;//slide the window towards its right
	        }
	    }
	    return min(res,len);
    }
};