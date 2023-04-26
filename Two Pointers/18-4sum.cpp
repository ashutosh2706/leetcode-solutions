class Solution {
#define ll long long
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

    if(nums.size() < 4) return {};
        
    sort(begin(nums), end(nums));
    set<vector<int>> S;
    for(int i=0; i<nums.size()-3; i++) {

        if(i > 0 && nums[i] == nums[i-1]) continue;

        for(int j = i+1; j < nums.size()-2; j++) {

            for(int l=j+1; l<nums.size()-1; l++) {
    
                ll rem = (ll)target - ((ll)nums[i] + (ll)nums[j] + (ll)nums[l]);
                int start = l+1, end = nums.size()-1, mid;
                while(start <= end) {
                    mid = start + (end-start)/2;
                    if(nums[mid] == rem) { S.insert({nums[i], nums[j], nums[l], nums[mid]}); break; }
                    if(nums[mid] > rem) end = mid-1;
                    else start = mid+1;
                }

            }

        }
    }

    return vector<vector<int>>(begin(S), end(S));
    }
};