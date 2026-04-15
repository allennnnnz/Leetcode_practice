class Solution {
public:
    int minPairSum(vector<int>& nums) {
        static const int MAXV = 100000;
        vector<int> cnt(MAXV + 1, 0);

        for (int x : nums) cnt[x]++;

        int lo = 1, hi = MAXV;
        int ans = 0;
        int pairs = (int)nums.size() / 2;

        while (pairs--) {
            while (lo <= MAXV && cnt[lo] == 0) lo++;
            while (hi >= 1 && cnt[hi] == 0) hi--;

            // 取一個最小、取一個最大
            cnt[lo]--;
            cnt[hi]--;

            ans = max(ans, lo + hi);
        }
        return ans;
    }
};