namespace user {
    string to_string(int i) {
        string res = "";
        if(i >= 0 and i <= 9) return res += (i+'0');
        return std::to_string(i);
    }
}
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
    int n = nums.size(),start = 0;
    vector<string> res;
    if(n==0) return res;
    while(start < n) {
        int end = start+1, prev = start;
        while(end < n and nums[end] == nums[prev] + 1) prev = end++;
        if(nums[start] == nums[prev]) res.push_back(user::to_string(nums[prev]));
        else {
            string s = user::to_string(nums[start]);
            s += "->";
            s += user::to_string(nums[prev]);
            res.push_back(s);
        }
        start = end;
    }
    return res;
    }
};