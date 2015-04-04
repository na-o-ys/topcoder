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

class LCA
{
public:
    int V, LOG_V, root;
    vector<vector<int>> G;
    vector<vector<int>> parent;
    vector<int> depth;

    LCA(vector<vector<int>> G, int root):
        G(G), V(G.size()), root(root) {
        LOG_V = 1;
        while (1<<LOG_V <= V) LOG_V++;
        parent = vector<vector<int>>(LOG_V, vector<int>(V));
        depth = vector<int>(V);
        init();
    };

    void dfs(int v, int p, int d) {
        parent[0][v] = p;
        depth[v] = d;
        for (int i = 0; i < G[v].size(); i++) {
            if (G[v][i] != p) dfs(G[v][i], v, d+1);
        }
    }

    void init() {
        dfs(root, -1, 0);
        for (int k = 0; k+1 < LOG_V; k++) {
            for (int v = 0; v < V; v++) {
                if (parent[k][v] < 0) parent[k+1][v] = -1;
                else parent[k+1][v] = parent[k][parent[k][v]];
            }
        }
    }

    int lca(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);
        for (int k = 0; k < LOG_V; k++) {
            if ((depth[v] - depth[u]) >> k & 1) v = parent[k][v];
        }
        if (u == v) return u;
        for (int k = LOG_V-1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
};

VVI G;
ll dist[2010];
int D[2010][2010];

void dfs(int u, int p, ll d) {
    dist[u] = d;
    for (int v : G[u]) if (v != p) dfs(v, u, d+D[u][v]);
}

int main(int argc, char const* argv[])
{
    int n; cin >> n;
    loop (n, i) loop (n, j) cin >> D[i][j];

    loop (n, i) loop (n, j) {
        if ((i != j && D[i][j] == 0) || (i == j && D[i][j] != 0) || D[i][j] != D[j][i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    G = VVI(n, VI(0));
    loop (n, i) {
        int Min = 1<<30, idx = 0;
        loop (n, j) if (i != j && D[i][j] < Min) Min = D[i][j], idx = j;
        G[i].push_back(idx);
        G[idx].push_back(i);
    }
    
    dfs(0, -1, 0);

    LCA lca(G, 0);

    loop (n, i) from_to (i+1, n-1, j) {
        if (D[i][j] == -1) continue;
        int par = lca.lca(i, j);
        // cout << "i: " << i << ", j: " << j << endl;
        // cout << "lca: " << par << endl;
        if (D[i][j] != dist[i] + dist[j] - 2 * dist[par]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}
