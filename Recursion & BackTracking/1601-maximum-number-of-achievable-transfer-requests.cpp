class Solution {
public:
    int ans = 0;
    void solve(int ind, vector<vector<int>>& req, vector<int> nodes, int l) {
        if(ind == req.size()) {
            for(auto &a:nodes) 
                if(a) return;
            ans = max(ans, l);
            return;
        }
        
        nodes[req[ind][0]] -= 1;
        nodes[req[ind][1]] += 1;
        solve(ind+1,req,nodes,l+1);
        nodes[req[ind][0]] += 1;
        nodes[req[ind][1]] -= 1;
        solve(ind+1, req,nodes,l);
        
        return;
        
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        
        vector<int>v(n);
        solve(0,requests,v,0);
        return ans;
    }
};