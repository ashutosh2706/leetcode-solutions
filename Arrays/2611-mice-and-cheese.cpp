class Solution {
public:
    int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {
    int n = r1.size();
    priority_queue<pair<int,int>> pq;
    for(int i=0; i<n; ++i) {
        pq.push({r1[i]-r2[i], i});
    } 

    int sum = accumulate(begin(r2),end(r2),0);
    while(k and pq.size() > 0) {
        sum -= r2[pq.top().second];
        sum += r1[pq.top().second];
        pq.pop();
        k--;
    }   
    return sum;
    }
};