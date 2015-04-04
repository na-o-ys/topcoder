#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;

const int Col = 4;
int dp[4][200001];

int dfs(vector<vector<int>>& sub, int i, int col)
{
    if (dp[0][i] == -1) loop (Col, c) {
        int v = 0;
        for (int s : sub[i]) v += dfs(sub, s, c);
        dp[c][i] = v + c + 1;
    }
    int ans = 1<<29;
    loop (Col, c) if (c != col) ans = min(ans, dp[c][i]);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    int T; cin >> T;
    loop (T, t) {
        int N; cin >> N;
        vector<vector<int>> sub(N);
        loop (N, i) {
            int m; cin >> m;
            if (m == 0) continue;
            sub[m-1].push_back(i);
        }
        fill(dp[0], dp[3]+200001, -1);
        int ans = dfs(sub, 0, -1);
        printf("Case #%d: %d\n", t+1, ans);
    }
    return 0;
}
