#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;
ll dp[301][301][601] = {};
const ll MOD = 1000000007;

int main()
{
    int N, K; cin >> N >> K;
    K++;
    string S; cin >> S;
    loop (N, i) {
        char c = S[i];
        if (c != '0') dp[i][i][K+1] = 1;
        if (c != '1') dp[i][i][K-1] = 1;
    }
    for (int d = 1; d < N; d++) {
        for (int i = 0; i + d < N; i++) {
            for (int k = 1; k < 2 * K; k++) {
                char c = S[i+d];
                if (k != 1       && c != '0') dp[i][i+d][k] += dp[i][i+d-1][k-1];
                if (k != 2*K - 1 && c != '1') dp[i][i+d][k] += dp[i][i+d-1][k+1];
                dp[i][i+d][k] %= MOD;
            }
        }
    }

    ll ans = 0;
    loop (N, i) loop (N, j) {
        if (i > j) continue;
        int sum = 0;
        for (int k = 1; k < 2 * K; k++) {
            sum += dp[i][j][k];
        }
        printf("%d, %d: %d\n", i, j, sum);
    }
    for (int k = 1; k < 2 * K; k++) {
        if (dp[0][N-1][k]) printf("%d, %d\n", k-K, dp[0][N-1][k]);
        ans += dp[0][N-1][k];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
