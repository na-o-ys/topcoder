#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

int main()
{
    int n; cin >> n;
    ll ans = 0;
    vector<vector<int>> m(n, vector<int>(n));
    loop (n, i) loop (n, j) cin >> m[i][j];
    loop (n, i) loop (n, j) ans += min(m[i][j], m[j][i]);
    cout << ans / 2 << endl;
    return 0;
}
