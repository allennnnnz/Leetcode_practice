class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int> diff(arr.size()-1);
        int minPair = INT_MAX;
        for(int i = 0 ; i<arr.size()-1 ; i++){
            diff[i] = abs(arr[i] - arr[i+1]);
            if(diff[i] <= minPair){
                minPair = diff[i];
            }
        }
        vector<vector<int>> result;
        vector<int> pair(2);
        for(int j=0 ; j<diff.size() ; j++ ){
            if(diff[j] == minPair){
                pair[0] = arr[j];
                pair[1] = arr[j+1];
                result.push_back(pair);
            }
        }
        return result;
    }
};