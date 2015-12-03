#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;
const int INF = 1<<29;

string S;

int score(int idx, int v) {
    if (S[idx] == 'M') {
        // 正
        pos[idx] - neg[idx] + score(idx+1, v+1);
        // 負
        neg[idx] - pos[idx] + score(idx+1, v-1);
    }
}

int main()
{
    int M = 1000;
    // i 番目で j の時の最大値
    int dp[1010][2010];
    fill(dp[0], dp[1009]+2010, -INF);
    dp[0][M] = 0;

    cin >> S;
    loop (S.size(), i) {
        for (int j = -1010; j < 1010; j++) {
            if (S[i] == '+') {
                dp[i+1][j+M] = dp[i][j+M] + j;
            }
            if (S[i] == '-') {
                dp[i+1][j+M] = dp[i][j+M] - j;
            }
            if (S[i] == 'M') {
                dp[i+1][j+M] = max(dp[i][j-1+M], dp[i][j+1+M]);
            }
        }
    }

    cout << dp[S.size()][M] << endl;
    return 0;
}
