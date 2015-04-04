#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
const int MAX_V = 101;
int G[MAX_V][MAX_V] = {};
int used[MAX_V] = {};
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
    int g, E; cin >> N >> g >> E;
    loop(g, i) {
        int p; cin >> p;
        G[p][N] = 1;
    }
    loop(E, i) {
        int a, b; cin >> a >> b;
        G[a][b] = 1;
        G[b][a] = 1;
    }
    int cnt = 0;
    while (dfs(0, N)) {
        fill(used, used+MAX_V, 0);
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
