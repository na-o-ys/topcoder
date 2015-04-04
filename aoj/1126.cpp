#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)

using namespace std;

int less_than(string a, string b)
{
    int d = a.length() - b.length();
    if (d) return d < 0;
    return a < b;
}

int main()
{
    while (1) {
        int w, h; cin >> w >> h;
        if (!w) break;
        vector<string> rows(h+1);
        loop (h, i) cin >> rows[i];

        string dp[80][80];
        fill(dp[0], dp[79]+80, "");

        for (int i = h-1; i >= 0; i--) {
            for (int j = w-1; j >= 0; j--) {
                if (rows[i][j] < 'A') {
                    dp[i][j] = rows[i][j] + max(dp[i+1][j], dp[i][j+1], less_than);
                }
            }
        }

        string ans = "";
        loop (h, i) loop (w, j) {
            if (rows[i][j] < 'A' && rows[i][j] != '0') {
                ans = max(ans, dp[i][j], less_than);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
