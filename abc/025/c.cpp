#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;
const int INF = 1<<29;

vector<vector<int>> b(3, vector<int>(3));
vector<vector<int>> c(3, vector<int>(3));

vector<int> dfs(vector<vector<int>> B, int cnt) {
    if (cnt == 9) {
        vector<int> sc = { 0, 0 };
        loop (2, i) loop (3, j) {
            sc[B[i][j] != B[i+1][j]] += b[i][j];
        }
        loop (3, i) loop (2, j) {
            sc[B[i][j] != B[i][j+1]] += c[i][j];
        }
        return sc;
    }

    int t = cnt%2;
    vector<int> sc = { -INF, -INF };
    loop (9, i) {
        if (B[i/3][i%3] != -1) continue;
        auto BB = B;
        BB[i/3][i%3] = t;
        auto scc = dfs(BB, cnt+1);
        if (sc[t] < scc[t]) sc = scc;
    }
    return sc;
}

int main()
{
    loop (2, i) loop (3, j) cin >> b[i][j];
    loop (3, i) loop (2, j) cin >> c[i][j];
    vector<vector<int>> B(3, vector<int>(3, -1));
    auto sc = dfs(B, 0);
    cout << sc[0] << endl;
    cout << sc[1] << endl;
}
