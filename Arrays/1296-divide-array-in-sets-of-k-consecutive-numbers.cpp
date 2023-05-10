class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int size) {
        
    int n = nums.size();
    if((n % size) != 0) return 0;
    map<int, int> mp;
    for(auto &i : nums) mp[i]++;
    while(mp.size() != 0) {
        int start = begin(mp)->first;
        for(int x = start; x < start+size; x++){
            if(mp.count(x)) {
                if(--mp[x] == 0) 
                    mp.erase(x);
            }else return 0;
        }
    }
    return 1;

    }
};