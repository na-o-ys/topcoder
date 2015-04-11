#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

const ll MOD = 1000000009;

int main(int argc, char const* argv[])
{
    int t; cin >> t;
    while (t--) {
        int k; cin >> k;
        ll n; cin >> n;

        ll dp[64][2] = {};
        if (n&1) {
            dp[0][0] = 1;
            dp[0][1] = 1;
        } else {
            dp[0][0] = 1;
            dp[0][1] = 1;
        }
        for (int i = 1; i < 64; i++) {
            int b = (n>>i)&1;
            if (b == 1) {
                dp[i][0] = (dp[i-1][0] + dp[i-1][1])%MOD;
                dp[i][1] = (dp[i-1][0] + dp[i-1][1])%MOD;
            } else {
                dp[i][0] = dp[i-1][0];
                dp[i][1] = (dp[i-1][0] + dp[i-1][1])%MOD;
            }
        }
        cout << dp[63][0] << endl;
    }
    return 0;
}
