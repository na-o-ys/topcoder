#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;

int G[101][101] = {};
int used[101] = {};
int N;

int dfs(int v, int t) {
    if (v == t) return 1;
    used[v] = 1;
    loop(N+1, i) {
        if (!G[v][i] || used[i] || !dfs(i, t)) continue;
        G[v][i] -= 1;
        G[i][v] += 1;
        return 1;
    }
    return 0;
}

int main(int argc, char const* argv[])
{
    int g, e; cin >> N >> g >> e;
    loop(g, i) {
        int p; cin >> p;
        G[p][N] = 1;
    }
    loop(e, i) {
        int a, b; cin >> a >> b;
        G[a][b] = 1;
        G[b][a] = 1;
    }
    int cnt = 0;
    while (dfs(0, N)) {
        fill(used, used+N+1, 0);
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
