class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b)
    {
        if(a.second != b.second)
            return a.second < b.second;

        return a.first < b.first;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> int_to_bit;
        for(int i = 0; i<arr.size(); i++){
            bitset<15> b(arr[i]);

            int count = 0;

            for(int j = 0; j < 15; j++)
            {
                if(b[j] == 1)
                    count++;
            }
            int_to_bit.push_back({arr[i],count});
        }
        sort(int_to_bit.begin(), int_to_bit.end(), cmp);
        vector<int> keys;

        for(auto p : int_to_bit)
        {
            keys.push_back(p.first);
        }
        return keys;
        
    }
};