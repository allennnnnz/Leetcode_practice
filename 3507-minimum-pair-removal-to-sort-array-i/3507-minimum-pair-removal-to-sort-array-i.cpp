class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;

        if (nums.size() <= 1) {
            return count;
        }

        bool non_decreasing = true;

        // 初始檢查
        for (int j = 0; j + 1 < (int)nums.size(); j++) {
            if (nums[j] > nums[j + 1]) {
                non_decreasing = false;
            }
        }

        while (!non_decreasing) {
            non_decreasing = true;   // ⭐ 必須重設

            int minSum = INT_MAX;       // ⭐ 每輪重設
            int index = -1;

            for (int i = (int)nums.size() - 2; i >= 0; i--) {
                if (nums[i] + nums[i + 1] <= minSum) {
                    minSum = nums[i] + nums[i + 1];
                    index = i;
                }
            }

            // ⭐ 防止 UB
            if (index == -1) break;

            nums[index] = minSum;
            nums.erase(nums.begin() + index + 1);

            for (int j = 0; j + 1 < (int)nums.size(); j++) {
                if (nums[j] > nums[j + 1]) {
                    non_decreasing = false;
                }
            }

            count++;
        }

        return count;
    }
};