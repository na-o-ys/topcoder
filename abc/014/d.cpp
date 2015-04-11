#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;
const int MAX_N = 1000010;
const int MAX_LOG_N = 22;

vector<int> G[MAX_N];
int parent[MAX_LOG_N][MAX_N] = {};
int depth[MAX_N] = {};
int root = 0;

void dfs(int v, int p, int d) {
    depth[v] = d;
    parent[0][v] = p;
    for (int w : G[v]) if (w != p) dfs(w, v, d+1);
}

int lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    for (int i = MAX_LOG_N; i>=0; i--) {
        if (depth[u] != depth[v]) v = parent[i][v];
    }
    if (u == v) return u;
    for (int i = MAX_LOG_N; i>=0; i--) {
        if (parent[i][u] != parent[i][v]) {
            u = parent[i][u];
            v = parent[i][v];
        }
    }
    return parent[0][u];
}

int main(int argc, char const* argv[])
{
    int N; cin >> N;
    loop (N, i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(1, 0, 0);
    loop (MAX_LOG_N, i) loop (MAX_N, j) parent[i+1][j] = parent[i][parent[i][j]];

    int Q; cin >> Q;
    loop (Q, i) {
        int a, b; cin >> a >> b;
        int anc = lca(a, b);
        cout << depth[a] + depth[b] - 2*depth[anc] << endl;
    }

    return 0;
}
