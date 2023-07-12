class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        vector<long long> v(begin(nums), end(nums));
        int N = nums.size();
        unordered_map<long long,int> map;
        for(int i=1; i<N; i++) {
            v[i] += v[i-1];
        }
        map[0] = -1;
        for(int i=0; i<N; i++) {
            long long mod = v[i] % k;
            if(map.count(mod)) {
                if(i - map[mod] >= 2) return 1;
            } else {
                map[mod] = i;
            }
        }
        return 0;
    }
};