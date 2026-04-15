class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        ans.reserve(nums.size());

        for (int n : nums) {
            // 必要條件：x | (x+1) 一定是奇數
            if ((n & 1) == 0) {
                ans.push_back(-1);
                continue;
            }

            // 找 n 的末尾連續 1 的長度
            // 例如 n=...0101111 => trailing ones = 4, mask=0b1111
            int t = 0;
            while (((n >> t) & 1) == 1) t++;
            int mask = (1 << t) - 1;        // t 個 1

            // 構造候選：把末尾連續 1 的最高那一位（bit t-1）翻成 0，其下保持 1
            // 等價於 x = n - 2^(t-1)
            int x = n - (1 << (t - 1));

            // 保險驗證（避免題意差異或邊界）
            if ( (x | (x + 1)) != n ) {
                ans.push_back(-1);
            } else {
                ans.push_back(x);
            }
        }
        return ans;
    }
};