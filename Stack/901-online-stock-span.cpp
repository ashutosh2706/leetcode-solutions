class StockSpanner {
public:
    stack<pair<int, int>> S;
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        pair<int, int> p;
        p.first = price;
        p.second = 1;
        while(!S.empty() && S.top().first <= price){
            p.second += S.top().second;
            S.pop();
        }
        S.push(p);
        return p.second;

    }
};