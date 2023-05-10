class Solution {
private:
int subseq(string &s1, string &s2, unordered_map<int, int> &map, int pos) {
    int p1 = 0, p2 = 0;
    while(p1 < s1.length() and p2 < s2.length()) {
        if(map.find(p1) != map.end() and map[p1] <= pos) {
            p1++;
            continue;
        }
        if(s1[p1] == s2[p2]) p2++;
        p1++;
    }
    return p2 == s2.length();
}

public:
    int maximumRemovals(string s, string p, vector<int>& nums) {
    
    unordered_map<int, int> map;
    for(int i=0; i<nums.size(); i++) map[nums[i]] = i;

    int l = 0, r = nums.size()-1;
    while(l <= r) {
        int mid = l + (r-l)/2;
        if(subseq(s, p, map, mid)) l = mid+1;
        else r = mid-1;
    }
    return r+1;
         
    }
};