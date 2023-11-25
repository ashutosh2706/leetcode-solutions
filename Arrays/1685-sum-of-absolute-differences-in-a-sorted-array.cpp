class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size(), sum=0;
        vector<int> left,right(n),res(n);
        for(int i=0; i<nums.size(); ++i) {
            left.push_back(sum+=nums[i]);
        }

        sum=0;
        for(int i=nums.size()-1; i>=0; --i) {
            right[i] = sum+=nums[i];
        }
        for(int i=0; i<nums.size(); ++i) {
            if(i==0) {
                res[i] = right[i+1] - ((n-1-i)*nums[i]);
            } else if(i==nums.size()-1) {
                res[i] = (nums[i] * i) - left[i-1];
            } else {
                res[i] = (nums[i] * i) - left[i-1];
                res[i] += (right[i+1] - ((n-1-i)*nums[i]));
            }
        }
        return res;
    }
};
