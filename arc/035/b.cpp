#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;
const ll MOD = 1000000007;

int main()
{
    int N; cin >> N;
    vector<int> T(N);
    loop (N, i) cin >> T[i];
    sort(all(T));

    ll sum = 0;
    loop (N, i) {
        sum += (ll)T[i] * (N - i);
    }

    ll fac[10010];
    fac[0] = 1;
    for (int i = 1; i < 10010; i++) {
        fac[i] = (i * fac[i-1]) % MOD;
    }

    int P[10010] = {};
    for (int t : T) P[t]++;
    ll ans = 1;
    for (ll p : P) {
        ans = (ans * fac[p]) % MOD;
    }

    cout << sum << endl;
    cout << ans << endl;
    return 0;
}
