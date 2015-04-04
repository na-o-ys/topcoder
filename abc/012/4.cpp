#include <iostream>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int N, M, d[301][301];
    cin >> N >> M;
    fill(d[0], d[N], 1<<29);
    loop (M, i) {
        int a, b, t; cin >> a >> b >> t;
        d[a-1][b-1] = d[b-1][a-1] = t;
    }

    loop (N, k) loop (N, i) loop (N, j) {
        d[i][j] = i == j ? 0 : min(d[i][j], d[i][k] + d[k][j]);
    }

    int ans = 1<<29;
    loop (N, i) ans = min(ans, *max_element(d[i], d[i]+N));

    cout << ans << endl;
    return 0;
}
