class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
    long long n = nums.size();
    long long total = (n * (n-1))/2;
    unordered_map<int, int> map;

    long long good = 0;

    for(int i=0; i<n; i++) {
        good = good + map[nums[i]-i]++;
    }    

    return total - good;

    }
};