class Solution {
private:

int arr[2502][2502];

int longest(int ind, int last, vector<int> &nums) {

    if(ind == nums.size()) return 0;

    if(last != -1 && arr[ind][last] != -1) return arr[ind][last];
    int take = 0;
    if(last == -1 || nums[ind] > nums[last]) 
        take = 1 + longest(ind+1, ind, nums);
    
    int not_take = longest(ind+1, last, nums);
    if(last != -1)
        return arr[ind][last] = max(take, not_take);

    return max(take, not_take);
}

public:
    int lengthOfLIS(vector<int>& nums) {
        memset(arr, -1, sizeof(arr));
        return longest(0, -1, nums);
    }
};