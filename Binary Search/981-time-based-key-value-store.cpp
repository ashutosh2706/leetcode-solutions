class TimeMap {
public:

    // binary search on timestamp 
    unordered_map<string, vector<pair<int, string>>> map;


    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int time) {
        if(!map.count(key)) return "";
        vector<pair<int, string>> v = map[key];
        int start = 0, end = v.size()-1;
        int mid = start + (end - start)/2;
        while(start <= end) {
            if(v[mid].first > time) end = mid-1;
            else if(v[mid].first < time) start = mid+1;
            else start = mid + 1;
            mid = start + (end - start)/2;
        }
        if(end == -1) return "";
        return v[end].second;
    }
};