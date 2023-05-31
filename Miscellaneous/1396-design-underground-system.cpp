class UndergroundSystem {
public:
    map<pair<string,string>, vector<int>> time;
    map<int, pair<string,int>> check;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        if(check.count(id) == 0) {
            check[id] = {stationName, t};
        } 
    }
    
    void checkOut(int id, string stationName, int t) {
        if(check.count(id)) {
            auto p = check[id];
            check.erase(id);
            time[{p.first,stationName}].push_back(t-p.second);
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        vector<int> times = time[{startStation, endStation}];
        long l = accumulate(begin(times),end(times),0);
        return (double)((double)l/(double)times.size());
    }
};