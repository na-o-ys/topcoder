#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

ll modpow(ll m, ll e, ll n) {
    ll ans = 1;
    ll b = m;
    loop (30, i) {
        if ((e>>i)&1) ans = (ans * b)%n;
        b = (b * b) % n;
    }
    return ans;
}

int main(int argc, char const* argv[])
{
    ll n, e, m; cin >> n >> e >> m;

    cout << modpow(m, e, n) << endl;;
    return 0;
}
