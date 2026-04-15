class Solution {
public:
    int minimumCost(vector<int>& nums) {

        int result = INT_MAX;
        if(nums.size() == 3){
            result=0;
            for(int i=0 ;i<3 ;i++){
                result += nums[i];
            }
            return result;
        }

        int min1 = INT_MAX, min2 = INT_MAX;

        for (int x = 1 ;x<nums.size();x++) {
            if (nums[x] < min1) {
                min2 = min1;
                min1 = nums[x];
            } else if (nums[x] < min2) {
                min2 = nums[x];
            }
        }
        return nums[0]+min1+min2;
    }
};