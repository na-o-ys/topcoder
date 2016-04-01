#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;
const int INF = 1<<29;
struct elem {
    int node, cost;
};

bool operator >(const elem& x, const elem& y) {
    return tie(x.cost, x.node) > tie(y.cost, y.node);
}

int main()
{
    while (1) {
END:
        int n, m, l, k, a, h; cin >> n >> m >> l >> k >> a >> h;
        if (!n) break;
        vector<int> L;
        loop (l, i) {
            int v; cin >> v;
            L.push_back(v);
        }
        L.push_back(h);
        vector<vector<int>> d(n, vector<int>(n, INF));
        loop (k, i) {
            int x, y, t; cin >> x >> y >> t;
            d[x][y] = t;
            d[y][x] = t;
        }
        loop (n, j) loop (n, i) loop (n, k) {
            d[i][k] = min(d[i][k], d[i][j] + d[j][k]);
        }

        priority_queue<elem, vector<elem>, greater<elem>> Q;
        Q.push({ a, 0 });
        vector<int> vis(n);
        while (Q.size()) {
            elem crr = Q.top(); Q.pop();

            if (vis[crr.node]) continue;
            vis[crr.node] = 1;
            if (crr.node == h) {
                int ans = crr.cost;
                if (ans > m) ans += ans - m;
                cout << ans << endl;
                goto END;
            }
            for (int nxt_node : L) {
                int cost = d[crr.node][nxt_node];
                if (cost <= m) {
                    Q.push({ nxt_node, crr.cost + cost });
                }
            }
        }
        cout << "Help!" << endl;
    }
    return 0;
}
