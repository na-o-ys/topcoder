#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
const int INF = 1<<29;
using ll = long long;

int main()
{
    int N, M; cin >> N >> M;
    vector<vector<int>> d(N, vector<int>(N, INF));
    loop (N, i) d[i][i] = 0;

    loop (M, i) {
        int a, b, c; cin >> a >> b >> c;
        d[a-1][b-1] = d[b-1][a-1] = c;
    }

    loop (N, k) loop (N, i) loop (N, j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }

    int K; cin >> K;
    loop (K, k) {
        int x, y, z; cin >> x >> y >> z;
        x--; y--;
        ll sum = 0;
        loop (N, i) loop (N, j) {
            d[i][j] = min(d[i][j], min(d[i][x] + d[y][j], d[i][y] + d[x][j]) + z);
            sum += d[i][j];
        }
        cout << sum/2 << endl;
    }
    return 0;
}
