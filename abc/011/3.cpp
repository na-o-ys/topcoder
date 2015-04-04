#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)
#define repeat(n) for(int i__=0;i__<n;i__++)
#define each(itr, c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)
#define r_each(itr, c) for(__typeof((c).rbegin()) itr=(c).rbegin(); itr!=(c).rend(); itr++)

using namespace std;
const int INF = 1000000000;

int main(int argc, char const* argv[])
{
    int N; cin >> N;
    int NG[3];
    loop(3, i) cin >> NG[i];

    if (NG[0] == N || NG[1] == N || NG[2] == N) { cout << "NO" << endl; return 0; }
    int dp[310];
    fill(dp, dp+310, INF);
    dp[N] = 0;
    for (int n = N; n > 0; n--) {
        if (dp[n] != INF) {
            loop(3, i) {
                if (n-i-1 < 0) break;
                if (NG[0] == n-i-1 || NG[1] == n-i-1 || NG[2] == n-i-1) continue;
                dp[n-i-1] = min(dp[n-i-1], dp[n] + 1);
            }
        }
    }
    if (dp[0] <= 100) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
