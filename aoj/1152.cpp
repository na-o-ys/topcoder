#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
ll dp[210][10010] = {};

int main()
{
    int n, w; cin >> n >> w;
    vector<int> W(n);
    loop (n, i) cin >> W[i];

    sort(all(W));

    // dp[i][j] : i 以降を使って重さ j 以上 w 以下のパターン数
    dp[n][0] = 1;
    for (int i = n-1; i >= 0; i--) loop (w+1, j) {
        dp[i][j] = dp[i+1][j]
            + dp[i+1][max(j - W[i], 0)]
            - dp[i+1][max(w - W[i] + 1, 0)];
        dp[i][j] %= MOD;
    }

    loop (n, i) {
        //cout << i << ": ";
        loop (w+1, j) {
            if (dp[i][j] < 0) cout << "error" << endl;
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }

    ll S = 0;
    for (int v : W) S += v;
    if (S <= w || W[0] > w) { cout << 1 << endl; return 0; }

    ll ans = 0;
    int sum = 0;
    loop (n-1, i) {
        ans += dp[i+1][max(w - sum - W[i] + 1, 0)] - dp[i+1][w - sum + 1];
        ans %= MOD;
        sum += W[i];
        if (w < sum) break;
    }
    cout << ans << endl;
    return 0;
}
