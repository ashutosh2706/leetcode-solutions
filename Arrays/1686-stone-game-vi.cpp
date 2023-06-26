class Solution {
public:
    int stoneGameVI(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>> v;
        for(int i=0; i<nums1.size(); i++) {
            v.push_back(vector<int>{nums1[i]+nums2[i], nums1[i], nums2[i]});
        }
        sort(begin(v),end(v),[](vector<int>& a, vector<int>& b){
            if(a[0] != b[0]) return a[0]>b[0];
            return a[1]>b[1];
        });
        int alice = 0, bob = 0;
        for(int i=0; i<v.size(); i++) {
            if(i%2==0) alice += v[i][1];
            else bob += v[i][2];
        }
        if(alice > bob) return 1;
        if(bob > alice) return -1;
        return 0;
    }
};