class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size() == 1) return {nums[0]};
        int n1 = INT_MAX, n2 = INT_MAX, c1=0, c2=0;
        for(int i=0; i<nums.size(); ++i) {
            if(nums[i] == n1) c1++;
            else if(nums[i] == n2) c2++;
            else if(c1 == 0) {
                n1 = nums[i];
                c1 = 1;
            }
            else if(c2==0) {
                n2 = nums[i];
                c2 = 1;
            } 
            else { c1--; c2--; }

        }
        cout << n1 << " " << n2;
        c1=0, c2=0;
        for(auto &a:nums) {
            if(a == n1) c1++;
            else if(a == n2) c2++;
        }
        
        int n = nums.size();
        if(c1 > (int)(n/3) and c2 > (int)(n/3)) return vector<int>{n1, n2};
        else if(c1 > (int)(n/3)) return {n1};
        else if(c2 > (int)(n/3)) return {n2};
        return {};
    }
};