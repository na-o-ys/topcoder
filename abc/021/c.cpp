#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = 1LL<<32;

int main()
{
    int N; cin >> N;
    int a, b; cin >> a >> b;
    a--, b--;
    int M; cin >> M;
    ll d[110][110];
    ll cnt[110][110] = {};
    fill(d[0], d[109]+110, INF);
    loop (M, i) {
        int x, y; cin >> x >> y;
        x--, y--;
        d[x][y] = d[y][x] = 1;
        cnt[x][y] = cnt[y][x] = 1;
    }


    loop (N, k) loop (N, i) loop (N, j) {
        if (d[i][j] < d[i][k] + d[k][j]) continue;
        if (d[i][j] > d[i][k] + d[k][j]) cnt[i][j] = 0;
        cnt[i][j] = (cnt[i][j] + ((cnt[i][k] * cnt[k][j]) % MOD)) % MOD;
        d[i][j] = d[i][k] + d[k][j];
    }

    cout << cnt[a][b] << endl;
    // while (1) {
    //     int a, b; cin >> a >> b;
    //     a--, b--;
    //     cout << cnt[a][b] << endl;
    // }
    return 0;
}
