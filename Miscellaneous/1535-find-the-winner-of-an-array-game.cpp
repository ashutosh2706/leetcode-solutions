class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        if(k >= n) {
            return *max_element(begin(arr), end(arr));
        }

        queue<int> q;
        for(auto &a:arr) q.push(a);
        int a = q.front(), cnt = 0; q.pop();
        while(!q.empty()) {
            int b = q.front();
            q.pop();
            if(a > b) {
                q.push(b);
                ++cnt;
            } else {
                q.push(a);
                a = b;
                cnt = 1;
            }
            if(cnt == k) return a;
        }
        return -1;
    }
};