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
    int t, k; cin >> t >> k;
    ll ans[100010] = {};
    from_to (1, k-1, i) ans[i] = i;
    from_to (k, min(2*k-1, 100001), i) ans[i] = (ans[i-1] + 1 + i-k + 1) % MOD;
    from_to (2*k, 100001, i) {
        ans[i] = (2*MOD + ans[i-k] - ans[i-2*k] + ans[i-k] - ans[i-k-1] + ans[i-1]) % MOD;
    }

    loop (t, i) {
        int a, b; cin >> a >> b;
        cout << (MOD + ans[b] - ans[a-1])%MOD << endl;
    }

    return 0;
}
