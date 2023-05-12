class Solution {
private:
long long A[100001];
long long maxPoints(int ind, vector<vector<int>> &nums) {
    if(ind >= nums.size()) return 0;
    if(A[ind] != -1) return A[ind];
    long long taken = nums[ind][0] + maxPoints(ind+1+nums[ind][1], nums);
    long long not_taken = maxPoints(ind+1, nums);
    return A[ind] = max(taken, not_taken);
}
public:
    long long mostPoints(vector<vector<int>>& nums) {
    memset(A, -1, sizeof(A));
    return maxPoints(0, nums);
    }
};