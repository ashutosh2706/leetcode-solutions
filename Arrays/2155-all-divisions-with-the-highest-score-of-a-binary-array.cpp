class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        map<int, vector<int>>map;
        int one = accumulate(begin(nums), end(nums), 0), zero = 0;

        for(int i=0; i<=nums.size(); i++) {
            map[zero+one].push_back(i);
            if(i == nums.size()) break;
            nums[i] ? one-- : zero++;
        }

        return prev(end(map))->second;
    }
};