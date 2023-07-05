class Solution {
private:
    void SieveOfEratosthenes(int n, vector<int>& primes) {
       primes.resize(n+1, 1);
        for (int p = 2; p*p <= n; p++) {
            if (primes[p]) {
                for (int i = p*p; i <= n; i += p)
                    primes[i] = 0;
            }
        }
        primes[0] = primes[1] = 0;
    }
public:
    int minSteps(int n) {
        if(n==1) return 0;
        vector<int> primes;
        SieveOfEratosthenes(n+1, primes);
        int steps = 0;
        while(n > 1) {
            if(primes[n]) {
                steps += n;
                break;
            }
            int u = floor(sqrt(n));
            for(int i=2; i<=u; i++) {
                if(n%i == 0) {
                    steps += i;
                    n /= i;
                    break;
                }
            }
        }
        return steps;
    }
};