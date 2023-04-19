// Time: O(nlogn)
// Space O(1)

class Solution {
public:
    string largestNumber(vector<int>& nums) {

    sort(begin(nums), end(nums), [](int x, int y) {

        string s1 = to_string(x);
        string s2 = to_string(y);
        string p = s1 + s2;
        string q = s2 + s1;
        return stoll(p) > stoll(q);

    });

    int i = 0;
    while(i < nums.size() - 1 && nums[i] == 0) i++;
    string res = "";
    for(; i<nums.size(); i++) res += to_string(nums[i]);
    return res;
    
    }
};