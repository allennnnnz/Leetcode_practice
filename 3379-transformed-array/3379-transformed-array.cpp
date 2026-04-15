class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> result(nums.size());
        int idx = 0;
        int n = nums.size();
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] > 0){
                if(i+nums[i]>=nums.size()){
                    result[i] =  nums[(i+nums[i])%nums.size()];
                }else{
                    result[i] =  nums[i+nums[i]];
                }
            }
            if(nums[i] < 0){
                if(i+nums[i]<0){
                    result[i] = nums[((i + nums[i]) % n + n) % n];
                }else{
                    result[i] =  nums[i+nums[i]];
                }
            }
            if(nums[i]==0){
                result[i] = nums[i];
            }
        }
        return result;
    }
};