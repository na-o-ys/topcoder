#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
using ld = long double;

int main()
{
    cout << setprecision(10) << fixed;

    ld cmb[101][101] = {};
    loop (101, i) {
        cmb[i][0] = 1;
        for (int j = 1; j <= i; j++) cmb[i][j] = cmb[i-1][j-1] + cmb[i-1][j];
    }

    ld dp[101] = {};
    for (int i = 2; i <= 100; i++) {
        ld e = 0;
        ld p_draw = 0;
        loop (i+1, a) loop (i+1, b) {
            int c = i-a-b;
            if (c < 0) continue;

            ld p = cmb[i][a] * cmb[i-a][b] / pow(3.0l, i);
            int cnt[3] = {a, b, c};
            sort(cnt, cnt+3);

            if (cnt[0] == cnt[2] || !cnt[0] && !cnt[1]) { p_draw += p; continue; }
            if (!cnt[0]) cnt[0] = cnt[1];
            e += (dp[cnt[0]] + 1) * p;
        }

        dp[i] = (p_draw + e) / (1.0l - p_draw);
    }

    int n;
    cin >> n;
    cout << dp[n] << endl;
    return 0;
}
