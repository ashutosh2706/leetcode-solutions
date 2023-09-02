class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    unordered_map<int,int> map;
    for(int i=0; i<arr.size(); ++i) {
        map[arr[i]]=i;
    }
    int ans = arr.size()-1;
    for(auto &v : mat) {
        int maxi = 0;
        for(auto &i : v) {
            maxi = max(maxi, map[i]);
        }
        ans = min(ans, maxi);
    } 

    for(int i=0; i<mat[0].size(); ++i) {
        int maxi = 0;
        for(int j=0; j<mat.size(); ++j) {
            maxi = max(maxi, map[mat[j][i]]);
        }
        ans = min(ans, maxi);
    } 

    return ans;
    }
};