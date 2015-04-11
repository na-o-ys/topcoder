#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll modpow(ll a, ll n)
{
    ll ret = 1;
    ll base = a;
    loop (33, i) {
        if ((n >> i) & 1) ret = (ret * base) % MOD;
        base = (base * base) % MOD;
    }
    return ret;
}

ll inv(ll n)
{
    return modpow(n, MOD-2);
}

ll cmb(ll n, ll k)
{
    ll a = 1, b = 1;
    loop (k, i) a = (a * (n - i)) % MOD;
    loop (k, i) b = (b * (k - i)) % MOD;
    return (a * inv(b)) % MOD;
}

int main()
{
    int n, k; cin >> n >> k;
    ll a = 1, b = 1;
    cout << cmb(n + k - 1, n - 1) << endl;

    return 0;
}
