class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it = lower_bound(begin(nums), end(nums), target);
        auto it2 = upper_bound(begin(nums), end(nums), target);
        if(it!=end(nums) and it2!=begin(nums) and *it==target) {
            int first = it-begin(nums);
            int last = --it2-begin(nums);
            return vector<int>{first, last};
        }
        return vector<int>{-1,-1};
    }
};