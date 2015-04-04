#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)

using namespace std;
const int INF = 1<<29;
const int MAX = 20010;

int main()
{
    int N; cin >> N;
    vector<int> a(N);
    loop (N, i) cin >> a[i];

    vector<int> cost(MAX+1, INF);
    cost[0] = 0;

    queue<int> q;
    q.push(0);
    while (q.size()) {
        int u = q.front();
        q.pop();
        loop (N, i) loop (N, j) {
            int v = u + 2*(a[i] - a[j]);
            if (v < 0 || v > MAX) continue;
            if (cost[v] > cost[u]+2) {
                cost[v] = cost[u]+2;
                q.push(v);
            }
        }
    }

    int Q; cin >> Q;
    while (Q--) {
        int s, t; cin >> s >> t;
        int ans = cost[abs(t-s)];
        for (int b : a) {
            ans = min(ans, cost[abs(2*b - s - t)] + 1);
        }
        cout << (ans < INF ? ans : -1) << endl;
    }
    return 0;
}
