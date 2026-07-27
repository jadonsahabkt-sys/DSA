class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int>freq;

        //Count frequence of each element
        for(int num : arr){
            freq[num]++;
        }

        unordered_set<int>seen;

        //check if frequencies are unique
        for(auto it :freq){
            if(seen.count(it.second)){
                return false;
            }
            seen.insert(it.second);
        }
        return true;
    }
};