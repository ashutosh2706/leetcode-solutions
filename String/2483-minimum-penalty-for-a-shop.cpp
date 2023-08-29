class Solution {
public:
    int bestClosingTime(string customers) {
    int n = customers.length();

    vector<int> v1(n+1), v2(n);
    if(customers.front() == 'N') v1[0] = 1;
    for(int i=1; i<=n; ++i) {
        if(i == n) {
            v1[n] = v1[n-1];
            continue;
        }
        if(customers[i] == 'N') v1[i] = v1[i-1]+1;
        else v1[i] = v1[i-1];
    }

    if(customers.back() == 'Y') v2.back() = 1;
    for(int i=n-2; i>=0; --i) {
        if(customers[i] == 'Y') v2[i] = v2[i+1]+1;
        else v2[i] = v2[i+1];
    }

    int ind, ans = INT_MAX;
    for(int i=0; i<=n; ++i) {
        int sum;
        if(i == 0) {
            sum = v2[i];
        } else if(i == n) sum = v1[i-1]; 
        else 
            sum = v1[i-1] + v2[i];

        if(sum < ans) {
            ans = sum;
            ind = i;
        }
    }
    return ind;
    }
};