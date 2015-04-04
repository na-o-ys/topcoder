#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

const int MAX_V = 1000000;
const int INF = 1 << 30;
struct edge { int to, cap, rev; };
vector<edge> G[MAX_V];

void add_edge(int from, int to, int cap) {
    G[from].push_back(edge { to, cap, (int)G[to].size() });
    G[to].push_back(edge { from, 0, (int)G[from].size()-1 });
}

bool used[MAX_V];
int dfs (int v, int t, int f) {
    if (v == t) return f;
    used[v] = true;
    for (edge& e : G[v]) {
        if (used[e.to] || e.cap <= 0) continue;
        int d = dfs(e.to, t, min(f, e.cap));
        if (d == 0) continue;
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
    }
    return 0;
}

int max_flow(int s, int t) {
    int flow = 0;
    while (1) {
        fill(used, used+MAX_V, 0);
        int f = dfs(s, t, INF);
        if (f == 0) return flow;
        flow += f;
    }
}

int main(int argc, char const* argv[])
{
    int N, G, E;
    cin >> N >> G >> E;
    loop(G, i) {
        int pi; cin >> pi;
        add_edge(pi, N, 1);
    }
    loop(E, i) {
        int a, b; cin >> a >> b;
        add_edge(a, b, 1);
        add_edge(b, a, 1);
    }
    cout << max_flow(0, N) << endl;
    return 0;
}
