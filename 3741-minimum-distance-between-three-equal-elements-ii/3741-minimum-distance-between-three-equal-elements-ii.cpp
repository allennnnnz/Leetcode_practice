class Solution {
public:
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
};