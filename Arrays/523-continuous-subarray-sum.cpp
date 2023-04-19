// Prefix Sum + Hashing


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        vector<long long> v(nums.size());
        map<int, int> map;
        v[0] = nums[0];
        map[nums[0] % k] = 0;
        for(int i=1; i<nums.size(); i++) {
            v[i] = nums[i] + v[i-1];
            int rem = v[i] % k;
            if(rem == 0) return 1;
            if(map.count(rem)) {
                if(i - map[rem] >= 2) return 1; 
            }else map[rem] = i;
        }
        return 0;

    }
};