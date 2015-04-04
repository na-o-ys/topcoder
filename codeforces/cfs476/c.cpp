#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;
const ll MOD = 1000000007;

int main(int argc, char const* argv[])
{
    ll a, b; cin >> a >> b;
    ll ans = (a*(a+1)/2)%MOD;
    ans = (ans * b) % MOD;
    ans = (ans * ((b*(b-1)/2) % MOD)) % MOD;
    ans = ans + (((b*(b-1)/2) % MOD) * a) % MOD;
    cout << ans % MOD << endl;
    return 0;
}
