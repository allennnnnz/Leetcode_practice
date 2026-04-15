class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int last_val = nums[0];
        int idx = 1;
        while(last_val<nums[idx]){
            last_val = nums[idx];
            idx++;
            if(idx == nums.size()){
                return false;
            }
            
        }
        if(idx==1 ){
            cout<<"stop 1"<<idx<<" idx";
            return false;
        }
        int p = idx;
        cout<<idx<<" idx";
        while(last_val>nums[idx]){
            last_val = nums[idx];
            idx++;
            if(idx == nums.size()){
                return false;
            }
            
        }
        if(idx == p ){
            cout<<"stop 2";
            return false;
        }

        for(int i=idx ;i < nums.size() ;i++){
            if(last_val>=nums[i]){
                cout<<"last "<< last_val<<' ';
                cout<<"cur "<<nums[i]<<' ';
                return false;
            }
            last_val = nums[i];
        }
        return true;
    
    }
};
