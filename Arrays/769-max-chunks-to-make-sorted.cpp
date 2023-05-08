class Solution {
public:
    int maxChunksToSorted(vector<int>& nums) {
        
        int n = nums.size();
        int chunks = n;
        vector<int> v(n);
        for(int i=0; i<n; i++) {
            v[nums[i]] = 1;
            for(int x = 0; x <= i; x++) {
                if(!v[x]) {
                    chunks--;
                    break;
                }
            }

        }
        return chunks;
    }
};