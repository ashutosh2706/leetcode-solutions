class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
    priority_queue<int> pq;
    for(auto &a : stones) pq.push(a);

    while(pq.size() > 1) {
        int b = pq.top();
        pq.pop();
        int s = pq.top();
        pq.pop();
        if(b != s) pq.push(b-s);
    }
    
    return (int)pq.size() == 0 ? 0 : pq.top();
    
    }
};