class Solution {
public:
    int minProcessingTime(vector<int>& pt, vector<int>& tasks) {
        sort(begin(tasks), end(tasks));
        sort(begin(pt),end(pt));
        int ans = 0, ind = tasks.size()-1;
        for(int i=0; i<pt.size(); ++i) {
            ans = max(ans, max({pt[i]+tasks[ind], pt[i]+tasks[ind-1], pt[i]+tasks[ind-2], pt[i]+tasks[ind-3]}));
            ind -= 4;
        }
        return ans;
    }
};