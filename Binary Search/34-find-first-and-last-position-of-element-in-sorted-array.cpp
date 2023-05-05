class Solution {
private:
    int first(vector<int>& nums, int target) {
    int a=0, b=nums.size()-1,mid;
    mid=b/2;
    int res=-1;
    while(a<=b) {
        if(nums[mid]>target) b=mid-1;
        else if(nums[mid]<target) a=mid+1;
        else if(nums[mid]==target) { res=mid; b=mid-1; }
        mid=(a+b)/2;
    }
    return res; 
    }
    
    int last(vector<int>& nums, int target) {
    int a=0, b=nums.size()-1,mid;
    mid=b/2;
    int res=-1;
    while(a<=b) {
        if(nums[mid]>target) b=mid-1;
        else if(nums[mid]<target) a=mid+1;
        else if(nums[mid]==target) { res=mid; a=mid+1; }
        mid=(a+b)/2;
    }
    return res;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        res.push_back(first(nums,target));
        res.push_back(last(nums,target));
        return res;
    }
};