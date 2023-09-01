class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        // wrong answer => accepted 
        int x = startPos.front(), y = startPos.back();
        int tx = homePos.front(), ty = homePos.back();
        int cost = 0;
        while(tx < x) cost += rowCosts[--x];
        while(tx > x) cost += rowCosts[++x];
        while(ty < y) cost += colCosts[--y];
        while(ty > y) cost += colCosts[++y];
        return cost;
    }
};