#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;
using P = pair<int, int>;
using tpl = tuple<int, int, int>;
using VI = vector<int>;
using VVI = vector<VI>;
const int INF = 1<<29;
const int MAX_LOG_V = 15;
const int MAX_V = 2010;

int V;
vector<P> G[MAX_V];
int DEP[MAX_V], DIST[MAX_V];
int PAR[MAX_LOG_V][MAX_V];

void dfs(int v, int par, int dep, int dist) {
    DEP[v] = dep;
    PAR[0][v] = par;
    DIST[v] = dist;
    for (P p : G[v]) {
        int to = p.first, _dist = p.second;
        if (par == to) continue;
        dfs(to, v, dep+1, _dist+dist);
    }
}

void init(int root) {
    dfs(root, -1, 0, 0);
    for (int k = 0; k+1 < MAX_LOG_V; k++) {
        for (int v = 0; v < V; v++) {
            if (PAR[k][v] < 0) PAR[k+1][v] = -1;
            else PAR[k+1][v] = PAR[k][PAR[k][v]];
        }
    };
}

int lca(int u, int v) {
    if (DEP[u] > DEP[v]) swap(u, v);
    loop (MAX_LOG_V, k) {
        if ((DEP[v] - DEP[u]) >> k & 1) v = PAR[k][v];
    }
    if (u == v) return u;
    for (int k = MAX_LOG_V - 1; k >= 0; k--) {
        if (PAR[k][u] != PAR[k][v]) {
            u = PAR[k][u];
            v = PAR[k][v];
        }
    }
    return PAR[0][u];
}

int main(int argc, char const* argv[])
{
    int n; cin >> n;
    V = n;
    VVI D(n, VI(n));
    loop (n, i) loop (n, j) cin >> D[i][j];

    loop (n, i) loop (n, j) {
        if ((i != j && D[i][j] == 0) || (i == j && D[i][j] != 0) || D[i][j] != D[j][i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    loop (n, i) {
        int m = 1<<30, m_j = 0;
        loop (n, j) if (i != j && D[i][j] < m) m = D[i][j], m_j = j;
        G[i].emplace_back(m_j, m);
        G[m_j].emplace_back(i, m);
    }

    init(0);

    loop (n, i) from_to (i+1, n-1, j) {
        if (D[i][j] == -1) continue;
        int par = lca(i, j);
        // cout << "i: " << i << ", j: " << j << endl;
        // cout << "lca: " << par << endl;
        if (D[i][j] != DIST[i] + DIST[j] - 2 * DIST[par]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}
