class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> available, processing;
    int n = tasks.size();
    for(int i=0; i<servers.size(); i++) available.push({servers[i], i});
    vector<int> res;
    int time = 0;
    for(int ptr = 0; ptr < n; ptr++) {
        time = max(time, ptr);
        if(available.empty()) 
            time = processing.top().first;

        while(!processing.empty() and processing.top().first <= time) {
            int idx = processing.top().second;
            processing.pop();
            available.push({servers[idx], idx});
        }

        auto p = available.top();
        available.pop();
        res.push_back(p.second);
        processing.push({time + tasks[ptr], p.second});

    }
    return res;
    }
};