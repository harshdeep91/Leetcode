class Solution {
public:
       int minDeletionSize(vector<string>& A) {
        int res = 0, n = A.size(), m = A[0].length(), i, j;
        vector<bool> sorted(n - 1, false);
        for (j = 0; j < m; ++j) {
            for (i = 0; i < n - 1; ++i) {
                if (!sorted[i] && A[i][j] > A[i + 1][j]) {
                    res++;
                    break;
                }
            }
            if (i < n - 1) continue;
            for (i = 0; i < n - 1; ++i) {
                sorted[i] = sorted[i] || A[i][j] < A[i + 1][j];
                // cout<<sorted[i]<<" ";
            }
            // cout<<endl;
        }
        return res;
    }
};
// if previous element > current element: remove that column immediately
// if previous element < current element: no need to compare previous row and current row again
// if previous element == current element: need to compare again.