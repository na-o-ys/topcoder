#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;
const ll MOD = 1000000007;
const double EPS = 1e-5;

int main()
{
    int n, k; cin >> n >> k;
    map<ll, ll, greater<ll>> M;
    for (ll i = 1; i * i <= k; i++) {
        if (k % i) continue;
        vector<ll> J = { i };
        if (i * i != k) J.push_back(k/i);
        for (auto j : J) {
            M[j] = ((1ll + (n/j)) * (n/j) / 2);
        }
    }
    for (auto p : M) {
        ll v = p.second;
        for (auto q : M) {
            if (q.first > p.first && q.first % p.first == 0) {
                v -= q.second * (q.first / p.first);
            }
        }
        M[p.first] = v;
    }
    ll ans = 0;
    for (auto p : M) {
        ans = (ans + p.second) % MOD;
    }
    cout << ((ans * k) % MOD) << endl;
    return 0;
}
