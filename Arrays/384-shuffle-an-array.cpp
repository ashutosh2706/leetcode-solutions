class Solution {
public:
    vector<int> v1;
    int n;
    Solution(vector<int>& nums) {
        n = nums.size();
        for(auto &i:nums) {
            v1.emplace_back(i);
        }
    }
    
    vector<int> reset() {
        return v1;
    }

    vector<int> shuffle() {
        vector<int> v2(begin(v1), end(v1));
        for(int i=0; i<n; i++) {
            swap(v2[i], v2[rand() % n]);
        }
        return v2;
    }
};