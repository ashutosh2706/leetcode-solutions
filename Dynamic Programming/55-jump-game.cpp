// dp solution

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
    vector<int> dp(n);
    dp[n-1] = 1;
    for(int i = n - 2; i >= 0; i--) {
        for(int x=1; x<=nums[i]; x++) {
            if(dp[i]) break; 
            if(i + x < n) {
                dp[i] = dp[i+x];
            }
        }
    }
    return dp[0];
    
    }
};



// bfs solution


class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        //bfs solution
        int n = nums.size();
        vector<int> vis(n);
        queue<pair<int, int>> q;
        q.push({0, nums[0]});   // { index, value }
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto p = q.front(); q.pop();
                if(p.first == n-1) return 1;
                for(int i = 1; i <= p.second; i++) {
                    int index = p.first + i;
                    if(index >= n) break;
                    if(!vis[index]) {
                        q.push({index, nums[index]});
                        vis[index] = 1;
                    }
                     
                }
            }
        }
        return 0;
    }
};