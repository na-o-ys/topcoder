#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;


int main(int argc, char const* argv[])
{
    int n, m; cin >> n >> m;
    vector<vector<int>> G(n);
    loop (m, i) {
        int a, b; cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
    loop (n, i) {
        int f[10] = {};
        f[i] = 1;
        for (int f1 : G[i]) f[f1] = 1;
        for (int f1 : G[i]) for (int f2 : G[f1]) if (!f[f2]) f[f2] = 2;
        int cnt = 0;
        for (int p : f) if (p == 2) cnt++;
        cout << cnt << endl;
    }
    return 0;
}
