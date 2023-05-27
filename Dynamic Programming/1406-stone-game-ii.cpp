class Solution {
private:
int A[50001];
int func(int ind, vector<int>& nums) {
    if(ind >= nums.size()) return 0;
    if(A[ind]!=-1) return A[ind];
    int ans = INT_MIN, sum = 0;
    for(int i=0; i<3; i++) {
        if(ind+i==nums.size()) break;
        sum+=nums[ind+i];
        ans = max(ans, sum - func(ind+i+1, nums));
    }
    return A[ind] = ans;
}
public:
    string stoneGameIII(vector<int>& nums) {
        memset(A,-1,sizeof(A));
        if(func(0,nums) < 0) return "Bob";
        if(func(0,nums) > 0) return "Alice";
        return "Tie";
    } 
};