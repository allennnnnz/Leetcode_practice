class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        string cur = words[startIndex];
        if(cur==target){
            return 0;
        }
        int size = words.size();
        for(int i=1 ; i<=words.size()/2 ; i++){
            cur = words[(startIndex+i)%size];
            if(cur == target){
                return i;
            }
            cur = words[(startIndex-i+size)%size];
            if(cur == target){
                return i;
            }
        }
        return -1;
    }
};