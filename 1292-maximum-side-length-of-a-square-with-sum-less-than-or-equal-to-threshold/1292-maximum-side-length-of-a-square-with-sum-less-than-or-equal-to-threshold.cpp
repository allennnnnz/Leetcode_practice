class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        if (mat.empty() || mat[0].empty()) return 0;  // 防止 mat[0] 越界

        int m = (int)mat.size();
        int n = (int)mat[0].size();
        int k = min(m, n);
        int result = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int start_k = 1;
                for ( start_k ; start_k <= k; start_k++) {
                    if (i + start_k > m || j + start_k > n) break;

                    long long count = threshold;
                    bool ok = true;

                    for (int start_i = i; start_i < i + start_k; start_i++) {
                        for (int start_j = j; start_j < j + start_k; start_j++) {
                            count -= mat[start_i][start_j];
                            if (count < 0) {
                                ok = false;
                                break;
                            }
                        }
                        if (!ok) break;
                    }

                    if (!ok) break;                 // ⭐ 直接放棄更大的 start_k，去下一個 (i,j)
                }
                if (start_k-1 > result) result = start_k-1;
            }
        }
        return result ;
    }
};