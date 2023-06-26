class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
    map<int, int> map;
    for(auto &i : nums) map[i]++;

    while(map.size() != 0) {
        int start = map.begin()->first;
        int prev = 0, x;
        for(x = start;;x++) {
            if(map.count(x)) {
                if(map[x] < prev) break;
                prev = map[x]--;
                if(map[x] == 0) map.erase(x);
            } else break;
        }
        if(x - start < 3) return 0;
    }
    return 1;

    }
};