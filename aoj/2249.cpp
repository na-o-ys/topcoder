#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

struct State { int node, dist, cost; };
bool operator>(const State& a, const State& b) {
    return tie(a.dist, a.cost) > tie(b.dist, b.cost);
}

int main()
{
    while (1) {
        int n, m; cin >> n >> m;
        if (!n) break;

        vector<vector<State>> G(n);
        loop (m, i) {
            int u, v, d, c; cin >> u >> v >> d >> c;
            u--, v--;
            G[u].push_back({ v, d, c });
            G[v].push_back({ u, d, c });
        }

        priority_queue<State, vector<State>, greater<State>> Q;
        Q.push({ 0, 0, 0 });
        vector<int> vis(n);
        ll ans = 0;
        while (Q.size()) {
            auto crr = Q.top(); Q.pop();

            if (vis[crr.node]) continue;
            vis[crr.node] = 1;
            ans += crr.cost;

            for (auto nxt : G[crr.node]) {
                Q.push({ nxt.node, crr.dist + nxt.dist, nxt.cost });
            }
        }
        cout << ans << endl;
    }
    return 0;
}
