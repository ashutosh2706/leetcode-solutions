class Solution {
public:
    int minDays(int n) {

    queue<int> q;
    q.push(n);
    unordered_set<int> set;
    int day = 0;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            int rem = q.front(); q.pop();
            if(rem == 0) return day;
            if(rem%3==0) {
                int eat = 2*(rem/3);
                if(set.count(rem-eat) == 0) {
                    q.push(rem - eat);
                    set.insert(rem-eat);
                }
            }
            if(rem%2==0 and set.count(rem - (rem/2)) == 0) {
                q.push(rem - (rem/2));
                set.insert(rem - (rem/2));
            }
            if(set.count(rem-1) == 0) {
                q.push(rem-1);
                set.insert(rem-1);
            }
        }
        day++;
    }
    return 1e9;
    }
};