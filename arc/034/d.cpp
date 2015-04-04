#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    double prod[160];
    prod[0] = 1;
    for (int i = 1; i < 159; i++) prod[i] = i * prod[i-1];

    int A, B, C; cin >> A >> B >> C;
    vector<int> va(A), vb(B);
    loop (A, i) cin >> va[i];
    loop (B, i) cin >> vb[i];

    vector<vector<int>> cnt(5010, vector<int>(51));
    cnt[0][0] = 1;
    for (int b : vb) {
        vector<vector<int>> cnt2 = cnt;
        loop (5010, i) loop (51, j) {
            if (cnt[i][j]) cnt2[i+b][j+1] += 1;
        }
        cnt = cnt2;
    }

    double ans = 0;
    for (int a : va) {
        loop (5010, i) loop (51, j) {
            if (!cnt[i][j]) continue;
            int former = j;
            double v = a;
            loop (B, j) {
                if (i>>j & 1) {
                    v *= vb[j];
                }
            }
            v *= (prod[former] * prod[C + B - former]) / prod[B + C + 1];
            ans += v;
        }
    }
    printf("%.12f\n", ans);
    return 0;
}
