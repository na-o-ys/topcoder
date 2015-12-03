#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

ll pow(ll a, ll n) {
    ll base = a;
    ll ans = 1;
    while (n) {
        if (n & 1) {
            ans = (ans * base) % MOD;
        }
        base = (base * base) % MOD;
        n >>= 1;
    }
    return ans;
}

ll inv(ll a) {
    return pow(a, MOD-2);
}

int main()
{
    ll a, b, c; cin >> a >> b >> c;

    ll num1 = (b*c - a*c + MOD * MOD) % MOD;
    ll num2 = (b*c - a*b + MOD * MOD) % MOD;
    ll den = (a*b + a*c - b*c + MOD * MOD) % MOD;

    ll x[2] = {
        num1 * inv(den) % MOD,
        num2 * inv(den) % MOD
    };

    cout << x[0] << " " << x[1] << endl;
    return 0;
}
