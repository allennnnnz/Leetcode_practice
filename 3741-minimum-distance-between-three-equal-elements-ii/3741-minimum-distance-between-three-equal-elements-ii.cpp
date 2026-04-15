class Solution {
public:
    /*
    int minimumDistance(vector<int>& nums) {
        int size = nums.size();
        int dis = INT_MAX;
        if(size<3){
            return -1;
        }
        //key nums[i] value pos
        map<int , vector<int>> count;
        for(int i=0 ; i < size ; i++){
            count[nums[i]].push_back(i); 
        }
        for(auto &c : count){
            if(c.second.size()<3){
                continue;
            }else{
                for(int j = 0 ; j+2 < c.second.size() ; j++){
                    int curdis = 2*(c.second[j+2] - c.second[j]);
                    if(dis>curdis){
                        dis = curdis;
                    }
                }
            }
            
        }
        if(dis == INT_MAX){
            return -1;
        }
        return dis;
    }
    */

    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> next(n, -1);
        std::unordered_map<int, int> occur;
        int ans = n + 1;

        for (int i = n - 1; i >= 0; i--) {
            if (occur.count(nums[i])) {
                next[i] = occur[nums[i]];
            }
            occur[nums[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            int secondPos = next[i];
            if (secondPos != -1) {
                int thirdPos = next[secondPos];
                if (thirdPos != -1) {
                    ans = std::min(ans, thirdPos - i);
                }
            }
        }

        return ans == n + 1 ? -1 : ans * 2;
    }
};
