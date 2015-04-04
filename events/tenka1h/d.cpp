#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

const int MOD = 1000000007;
int memo[3010][3010] = {};
int cmb(int n, int r) {
    if (memo[n][r]) return memo[n][r];
    if (n == r || r == 0) return 1;
    return memo[n][r] = ((ll)cmb(n-1, r-1) + cmb(n-1, r)) % MOD;
}
int dp[3010][3010] = {};
int main(int argc, char const* argv[])
{
    loop (3010, i) loop (3010, j) {
        if (j > i) {
            dp[i][j] = dp[i][i];
            continue;
        }
        if (j) {
            dp[i][j] = ((ll)dp[i][j-1] + cmb(i, j)) % MOD;
            continue;
        }
        dp[i][j] = 1;
    }

    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        cout << dp[n][k] << endl;
    }
    return 0;
}
