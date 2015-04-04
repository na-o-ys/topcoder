#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;
const ll MOD = 1000000007;

int n;
ll a, b, k;
ll dp[5010][5010];

int main(int argc, char const* argv[])
{
    cin >> n >> a >> b >> k;
    loop (n+1, i) dp[i][0] = 0;
    loop (k+1, i) dp[0][i] = 0;

    loop (n, i) {
        dp[i+1][0] = i+1 == b ? 0 : 1;
    }
    loop (n, i) dp[i+1][0] += dp[i][0];
    loop (k, j) loop (n, i) {
        int d = abs(i+1-b)-1;
        int top = min(i+1+d, n);
        int bottom = max(1, i+1-d);
        dp[i+1][j+1] = (dp[i][j+1]
                + dp[top][j] - dp[bottom-1][j]
                - dp[i+1][j] + dp[i][j]) % MOD;
    }
    cout << dp[a][k]-dp[a-1][k] << endl;
    return 0;
}
