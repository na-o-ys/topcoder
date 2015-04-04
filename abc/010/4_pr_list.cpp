#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
struct edge { int to, rev, cap; };
vector<edge> G[110];
int N, E;
int used[110] = {};

void addEdge(int v, int t) {
    G[v].push_back(edge { t, (int)G[t].size(), 1 });
    G[t].push_back(edge { v, (int)G[v].size()-1, 0 });
}

int dfs(int v) {
    if (v == N) return 1;
    used[v] = 1;
    for (edge& e : G[v]) {
        if (!e.cap || used[e.to] || !dfs(e.to)) continue;
        e.cap--;
        G[e.to][e.rev].cap++;
        return 1;
    }
    return 0;
}

int main(int argc, char const* argv[])
{
    int g;
    cin >> N >> g >> E;
    loop (g, i) {
        int p; cin >> p;
        addEdge(p, N);
    }
    loop (E, i) {
        int a, b; cin >> a >> b;
        addEdge(a, b);
        addEdge(b, a);
    }
    int ans = 0;
    while (dfs(0)) {
        fill(used, used+N+1, 0);
        ans++;
    }
    cout << ans << endl;
    return 0;
}
