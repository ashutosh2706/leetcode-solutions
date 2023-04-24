class NumArray {
public:
    vector<int> V;
    NumArray(vector<int>& nums) {
        V.push_back(nums.front());
        for(int i=1; i<nums.size(); i++) 
            V.push_back(nums[i] + V.back());
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return V[right];
        return V[right] - V[left-1]; 
    }
};