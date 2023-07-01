class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        
        
        auto func = [](int n, int f){
            if(n>=0 and n<=9) return n;
            char c;
            f ? c = to_string(n).front() : c = to_string(n).back();
            return c-'0';
        };
        
        
        int N = nums.size(), pairs = 0;
        for(int i=0; i<N-1; i++) {
            for(int j=i+1; j<N; j++) {
                int x = func(nums[i], 1), y = func(nums[j], 0);
                if(__gcd(x,y) == 1) pairs++;
            }
        }
        return pairs;
    }
};