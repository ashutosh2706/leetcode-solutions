class Solution {
private:
int f1(int t, vector<int> &nums, int s, int e) {
    int mid;
    while(s <= e) {
        mid = s + (e-s)/2;
        if(nums[mid] > t) e = mid-1;
        else if(nums[mid] < t) s = mid+1;
        else if(nums[mid] == t) return mid;
    }
    return -1;
}
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    
    set<vector<int>> S;
    sort(begin(nums), end(nums));

    for(int i=0; i<nums.size()-2; i++) {

        if(i > 0 && nums[i] == nums[i-1]) continue;
        if(nums[i] > 0) break;
        for(int j = i+1; j < nums.size()-1; j++) {
        int rem = -(nums[i] + nums[j]);
        int ret = f1(rem, nums, j+1, nums.size()-1);
        if(ret != -1) S.insert({nums[i],nums[j],nums[ret]});                    
        }

    }
    return vector<vector<int>>(begin(S), end(S));
    }
};