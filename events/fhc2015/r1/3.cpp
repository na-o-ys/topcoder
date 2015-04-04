#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;
const ll MOD = 1000000007;

int main()
{
    vector<vector<ll>> dp1(2010, vector<ll>(2010));
    dp1[1][0] = 1;
    loop (2001, i) loop (2001, j) {
        if (i <= j) continue;
        if (i-1 > j) dp1[i][j] += dp1[i-1][j];
        if (j-1 >= 0) dp1[i][j] += dp1[i][j-1];
        dp1[i][j] %= MOD;
    }
    vector<vector<ll>> dp2(2010, vector<ll>(2010));
    dp2[0][0] = 1;
    loop (2001, i) loop (2001, j) {
        if (i < j) continue;
        if (i-1 >= j) dp2[i][j] += dp2[i-1][j];
        if (j-1 >= 0) dp2[i][j] += dp2[i][j-1];
        dp2[i][j] %= MOD;
    }

    int T; cin >> T;
    loop (T, t) {
        string line; cin >> line;
        stringstream ss(line);
        string s;
        vector<int> score;
        while (getline(ss, s, '-')) {
            score.push_back(stoi(s));
        }
        if (score[0] <= score[1]) printf("Case #%d: 0 0\n", t+1);
        else printf("Case #%d: %d %d\n", t+1, dp1[score[0]][score[1]], dp2[score[1]][score[1]]);
    }
    return 0;
}
