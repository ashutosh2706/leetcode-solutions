class Solution {
public:
    int integerReplacement(int n) {

        queue<long> q;
        unordered_set<long> vis;
        q.push(n);
        vis.insert(n);
        int steps = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                long x = q.front(), y, z; 
                q.pop();
                if(x == 1) return steps;
                if(x%2) {
                    y = x-1;
                    z = x+1;
                    if(!vis.count(y)) {
                        vis.insert(y);
                        q.push(y);
                    }
                    if(!vis.count(z)) {
                        vis.insert(z);
                        q.push(z);
                    }
                } else {
                    if(!vis.count(x/2)) {
                        vis.insert(x/2);
                        q.push(x/2);
                    }
                }
            }
            steps++;
        }
        return -1;
    }   
};