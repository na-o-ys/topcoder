#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;

int main()
{
    int n, m; cin >> n >> m;
    int a[20]; loop (n, i) cin >> a[i];
    int b[60];
    vector<int> I[60];
    loop (m, i) {
        cin >> b[i];
        int c; cin >> c;
        I[i] = vector<int>(c);
        loop (c, j) cin >> I[i][j];
    }
    int ans = -1;
    loop (1<<n, i) {
        if (__builtin_popcount(i) != 9) continue;
        int point = 0;
        loop (m, j) {
            int hit = 0;
            for (int k : I[j]) if (i>>(k-1)&1) hit++;
            if (hit >= 3) point += b[j];
        }
        loop (n, j) if (i>>j&1) point += a[j];
        ans = max(ans, point);
    }
    cout << ans << endl;
    return 0;
}
