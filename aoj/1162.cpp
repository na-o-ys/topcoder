#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

struct State {
    int i, prev, sp; double cost;
};

bool operator>(const State& a, const State& b)
{
    return a.cost > b.cost;
}

const double INF = 1<<29;

int main()
{
    while (1) {
        int n, m, s, g; cin >> n >> m >> s >> g;
        if (!n) break;
        s--, g--;

        vector<vector<double>> dist(n, vector<double>(n, INF));
        vector<vector<int>> lim(n, vector<int>(n));

        while (m--) {
            int x, y, d, c; cin >> x >> y >> d >> c;
            x--, y--;
            dist[x][y] = dist[y][x] = d;
            lim[x][y] = lim[y][x] = c;
        }

        priority_queue<State, vector<State>, greater<State>> Q;
        Q.push({ s, 39, 0, 0 });

        int vis[40][40][40] = {};
        double ans = INF;
        while (Q.size()) {
            auto e = Q.top(); Q.pop();
            if (vis[e.i][e.sp][e.prev]) continue;
            vis[e.i][e.sp][e.prev] = 1;
            if (e.i == g && e.sp == 1) ans = min(ans, e.cost);
            loop (n, i) loop (3, d) {
                int sp = e.sp-1+d;
                if (dist[e.i][i] == INF || i == e.prev ||
                        sp < 1 || sp > lim[e.i][i]) continue;
                Q.push({ i, e.i, sp, e.cost + dist[e.i][i] / sp });
            }
        }
        if (ans != INF) cout << setprecision(12) << fixed << ans << endl;
        else cout << "unreachable" << endl;
    }
    return 0;
}
