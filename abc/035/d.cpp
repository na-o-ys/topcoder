#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

struct Edge { int to; ll cost; };
bool operator> (const Edge& a, const Edge& b) {
    return a.cost > b.cost;
}

const ll INF = 1LL<<59;

vector<ll> dijkstra(int n, vector<vector<Edge>>& G) {
    priority_queue<Edge, vector<Edge>, greater<Edge>> Q;
    Q.push({ 0, 0 });

    vector<ll> ans(n, INF);
    while (Q.size()) {
        Edge crr = Q.top(); Q.pop();
        if (ans[crr.to] != INF) continue;
        ans[crr.to] = crr.cost;
        for (Edge nxt : G[crr.to]) {
            Q.push({ nxt.to, nxt.cost + crr.cost });
        }
    }
    return ans;
}

int main()
{
    int n, m, t; cin >> n >> m >> t;

    vector<ll> A(n);
    loop (n, i) cin >> A[i];

    vector<vector<Edge>> G1(n), G2(n);
    loop (m, i) {
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        G1[a].push_back({ b, c });
        G2[b].push_back({ a, c });
    }

    auto D1 = dijkstra(n, G1);
    auto D2 = dijkstra(n, G2);

    ll ans = 0;
    loop (n, i) {
        if (D1[i] + D2[i] > t) continue;
        ans = max(ans, A[i] * (t - D1[i] - D2[i]));
    }
    cout << ans << endl;
    return 0;
}
