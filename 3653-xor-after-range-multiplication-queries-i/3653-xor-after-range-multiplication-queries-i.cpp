class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(int j=0 ; j<queries.size();j++){
            int start = queries[j][0];
            int step = queries[j][2];
            int border = queries[j][1];
            int mul = queries[j][3];
            int mod = pow(10, 9) + 7;

            int i = start;
            long tmp = 0;
            
            while(i<=border){
                if(i<nums.size()){
                    tmp = nums[i] ;
                    nums[i] = (tmp * mul) % mod;
                }
                
                
                i = i + step;
            }
        }
        int result  = nums[0];
     
        for(int i =1 ; i < nums.size() ;i++){
            cout<<nums[i]<<endl;
            result = result ^ nums[i];
        }
        return result;
    }
};