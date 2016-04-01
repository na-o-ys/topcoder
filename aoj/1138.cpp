#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;
struct Edge {
    int to; double cost;
};
const double INF = 1<<29;

int main()
{
    while (1) {
        int n, m, p, a, b; cin >> n >> m >> p >> a >> b;
        a--, b--;
        if (!n) break;

        vector<int> t(n);
        loop (n, i) cin >> t[i];

        vector<vector<Edge>> G(m);
        loop (p, i) {
            int x, y; double z; cin >> x >> y >> z;
            x--, y--;
            G[x].push_back({ y, z });
            G[y].push_back({ x, z });
        }

        double dp[300][31] = {};
        fill(dp[0], dp[299]+31, INF);
        dp[0][a] = 0;
        loop (n, i) {
            loop (1<<n, crr) if (__builtin_popcount(crr) == i) {
                loop (n, k) {
                    int nxt = crr | (1<<k);
                    if (nxt == crr) continue;
                    loop (m, from) {
                        for (auto e : G[from]) {
                            dp[nxt][e.to] = min(
                                dp[nxt][e.to],
                                dp[crr][from] + e.cost / t[k]
                            );
                        }
                    }
                }
            }
        }

        double ans = INF;
        loop (300, i) ans = min(ans, dp[i][b]);
        if (ans == INF) cout << "Impossible" << endl;
        else cout << setprecision(8) << fixed << ans << endl;
    }
    return 0;
}
