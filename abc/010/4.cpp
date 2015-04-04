#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)
#define repeat(n) for(int i__=0;i__<n;i__++)

using namespace std;
typedef pair<int, int> P;

int N, G, E;
int p[100];
vector<P> edge;
int V[100];
void dfs(int v, int i) {
    loop(edge.size(), j) {
        P p = edge[j];
        if ((i>>j) & 1) continue;
        if (p.first != v && p.second != v) continue;
        int w = p.first == v ? p.second : p.first;
        if (V[w]) continue;
        V[w] = 1;
        dfs(w, i);
    }
}

int main(int argc, char const* argv[])
{
    cin >> N >> G >> E;
    loop(G, i) cin >> p[i];
    repeat(E) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        edge.push_back(P(a, b));
    }

    int ans = 100000000;
    for (int i = 0; i>>12 == 0; i++) {
        fill(V, V+100, 0);
        dfs(0, i);
        int cnt = 0;
        loop(12, j) if ((i>>j)&1) cnt++;
        loop(G, j) if (V[p[j]]) cnt++;
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
