#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    int n, k; cin >> n >> k;
    vector<ll> f(n);
    loop (n, i) cin >> f[i];
    vector<ll> g = f;

    for (int i = n-2; i >= 0; i--) {
        g[i] += g[i+1];
    }

    for (int i = 0; i < n; i++) {
        if (i+k < n) g[i] -= g[i+k];
    }

    auto M = max_element(g.begin(), g.end());
    ll ans = *M;
    int idx = distance(g.begin(), M);

    vector<ll> h;
    for (int i = 0; i < n; i++) {
        if (i >= idx && i < idx+k) continue;
        h.push_back(f[i]);
    }

    for (int i = h.size()-2; i >= 0; i--) {
        h[i] += h[i+1];
    }

    for (int i = 0; i < h.size(); i++) {
        if (i+k < h.size()) h[i] -= h[i+k];
    }

    if (h.size()) ans += *max_element(h.begin(), h.end());
    cout << ans << endl;
    return 0;
}
