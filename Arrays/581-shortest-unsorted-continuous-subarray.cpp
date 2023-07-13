class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // vector<int> v(begin(nums),end(nums));
        // // a max-heap can also be used
        // sort(begin(v),end(v));
        // if(v == nums) return 0;
        // int mini = nums.size()-1, maxi = 0;
        // for(int i=0; i<nums.size(); i++) {
        //     if(v[i] != nums[i]) {
        //         maxi = max(maxi,i);
        //         mini = min(mini, i);
        //     }
        // }
        // return maxi-mini+1;

        // ---------------O(n) Solution-----------------

        int a = -1, b = -1;
        for(int i=0, x=nums[0]; i<nums.size(); i++) {
            if(nums[i] < x) b = i;
            x = max(x, nums[i]);
        }
        for(int i=nums.size()-1, x = nums[nums.size()-1]; i>=0; --i) {
            if(nums[i] > x) a = i;
            x = min(x, nums[i]);
        }
        if(a == -1 and b == -1) return 0;
        return (b-a+1);
    }
};