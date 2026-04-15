class Solution {
public:
    int longestBalanced(string s) {
        int count = 0;
        int result = 0;
        map<char , int> distinc;
        if(s.size()<=1){
            return s.size();
        }
        
        for(int i = 0 ;i<s.size() ; i++){
            distinc.clear();
            result = max(result,count);
 
            if(result>s.size()-i){
                return result;
            }
            for(int j =i ; j< s.size() ; j++){
                distinc[s[j]]++;
                int minFreq = INT_MAX;
                int maxFreq = INT_MIN;

                for (auto &p : distinc) {
                    minFreq = min(minFreq, p.second);
                    maxFreq = max(maxFreq, p.second);
                }

                if (minFreq == maxFreq) {
                    result = max(result, j - i + 1);
                }
            }
            cout<<count<<" ";

            
            
        }
        return result;
    }
};