class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& nums) {
        // slope same => straight line
        double slope = (double)(nums[1][1] - nums[0][1]) / (double)(nums[1][0] - nums[0][0]);
        for(int i=2; i<nums.size(); i++) {
            double m = (double)(nums[i][1] - nums[i-1][1]) / (double)(nums[i][0] - nums[i-1][0]);
            if(m != slope) return 0;
        }
        return 1;
    }
};