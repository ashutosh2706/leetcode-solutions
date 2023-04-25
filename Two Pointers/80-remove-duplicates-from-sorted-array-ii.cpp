class Solution {
public:
    int removeDuplicates(vector<int>& nums) {    
        int p1 = 0, p2 = 0;
        while(p2 < nums.size()) {
            int x = nums[p2], c = 1;
            nums[p1++] = nums[p2++];
            while(p2 < nums.size() && nums[p2] == x) {
                if(c < 2) {
                    nums[p1++] = nums[p2];
                    c++;
                }
                p2++;
            }
        }
        return p1;
    }
};