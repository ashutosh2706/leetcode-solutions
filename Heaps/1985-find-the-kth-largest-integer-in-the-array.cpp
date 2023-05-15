class Solution {
public:
    static bool cmpfunc(string &s1, string &s2) {
    if(s1.length() != s2.length())
        return s1.length() > s2.length();
    int n = s1.length();
    for(int i=0; i<n; i++) {
        if(s1[i] == s2[i]) continue;
        else {
            if(s1[i] - '0' > s2[i] - '0') return 1;
            break;
        }
    }
    return 0;
    }
    string kthLargestNumber(vector<string>& nums, int k) {
    sort(begin(nums), end(nums), cmpfunc);
    return nums[k-1];
    }
};