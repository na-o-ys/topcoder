#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;

ll f(ll x)
{
    if (x < 10) return x;
    return x % 10 + f(x / 10);
}

int main()
{
    vector<ll> ans;
    ll N; cin >> N;
    for (ll x = N-1000; x <= N; x++) {
        if (x + f(x) == N) ans.push_back(x);
    }
    cout << ans.size() << endl;
    for (ll x : ans) cout << x << endl;
    return 0;
}
