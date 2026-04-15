class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans_vector(size);
        for(int i=0 ; i<size;i++){
            int ans=0;
            if(nums[i]==2){
                ans = -1;
            }
            else{
               while((ans|(ans+1))!=nums[i]){
                    ans++;
                } 
            }
            
            ans_vector[i]=ans;
        }
        return ans_vector;  // 至少回傳一個 vector
    }
};