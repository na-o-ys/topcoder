#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;

const int MAX = 10000010;
const int MAX_P = 4000;

int main()
{
    vector<int> isPrime(MAX_P+1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i*i <= MAX_P; i++) {
        if (!isPrime[i]) continue;
        for (int j = i*i; j <= MAX_P; j += i) isPrime[j] = 0;
    }
    vector<int> primes;
    loop (MAX_P+1, i) if (isPrime[i]) primes.push_back(i);

    vector<int> P(MAX+1);
    for (int i = 2; i <= MAX; i++) {
        int n = i;
        for (int p : primes) {
            if (p > n) break;
            if (n%p == 0) P[i]++;
            while (n%p == 0) n /= p;
        }
        if (n != 1) P[i]++;
    }

    vector<vector<int>> cnt(10, vector<int>(MAX));
    for (int i = 1; i <= MAX; i++) {
        loop (10, j) cnt[j][i] = cnt[j][i-1];
        if (P[i]) cnt[P[i]][i] += 1;
    }

    int T; cin >> T;
    loop (T, t) {
        int a, b, k; cin >> a >> b >> k;
        int ans = 0;
        if (k < 10) {
            ans = cnt[k][b] - cnt[k][a-1];
        }
        printf("Case #%d: %d\n", t+1, ans);
    }
    return 0;
}
