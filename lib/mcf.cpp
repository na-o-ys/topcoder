typedef pair<int, int> P;
class MCF
{
public:
    MCF(int v): V(v) {}
    static const int MAX_V = 10000;
    const int INF = 1<<29;
    int V;
    struct edge { int to, cap, cost, rev; };
 
    vector<edge> G[MAX_V];
    int H[MAX_V];
    int D[MAX_V];
    int prevV[MAX_V];
    int prevE[MAX_V];
 
    void add_edge(int from, int to, int cap, int cost) {
        G[from].push_back(edge { to, cap, cost, (int)G[to].size() });
        G[to].push_back(edge { from, 0, -cost, (int)G[from].size()-1 });
    }
 
    int calc(int s, int t, int f) {
        int res = 0;
        fill(H, H+V, 0);
        while (f > 0) {
            priority_queue<P, vector<P>, greater<P>> q;
            fill(D, D+V, INF);
            D[s] = 0;
            q.emplace(0, s);
            while (!q.empty()) {
                P p = q.top(); q.pop();
                int v = p.second;
                if (D[v] < p.first) continue;
                for (int i = 0; i < G[v].size(); i++) {
                    edge e = G[v][i];
                    if (e.cap > 0 && D[e.to] > D[v] + e.cost + H[v] - H[e.to]) {
                        D[e.to] = D[v] + e.cost + H[v] - H[e.to];
                        prevV[e.to] = v;
                        prevE[e.to] = i;
                        q.emplace(D[e.to], e.to);
                    }
                }
            }
            if (D[t] == INF) return -1;
            for (int v = 0; v < V; v++) H[v] += D[v];
            int d = f;
            for (int v = t; v != s; v = prevV[v]) {
                d = min(d, G[prevV[v]][prevE[v]].cap);
            }
            f -= d;
            res += d * H[t];
            for (int v = t; v != s; v = prevV[v]) {
                edge &e = G[prevV[v]][prevE[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }
        return res;
    }
};
