#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll memo[100010][2] = {};
int degree[100010] = {};
vector<int> G[100010];

void dfs(int i, int d) {
    if (degree[i]) return;
    degree[i] = d;
    for (int j : G[i]) dfs(j, d+1);
}

// i 番目を col で塗った時の場合の数
ll dp(int i, int col) {
    if (memo[i][col]) return memo[i][col];
    ll ans = 1;
    for (int j : G[i]) if (degree[j] > degree[i]) {
        int child = 0;
        if (!col) child += dp(j, 1);
        child += dp(j, 0);
        child %= MOD;
        ans = (ans * child) % MOD;
    }
    return memo[i][col] = ans;
}

int main()
{
    int n; cin >> n;
    loop (n-1, i) {
        int a, b; cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
    dfs(0, 1);
    cout << ((dp(0, 0) + dp(0, 1)) % MOD) << endl;
    return 0;
}
