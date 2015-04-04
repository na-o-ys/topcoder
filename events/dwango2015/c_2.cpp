#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    double cmb[101][101] = {};
    loop (101, i) {
        cmb[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            cmb[i][j] = cmb[i-1][j-1] + cmb[i-1][j];
        }
    }

    int N; cin >> N;

    vector<double> E(N+1);
    for (int i = 2; i <= N; i++) {
        double p_d = 0, sum = 0;
        loop (i+1, a) loop (i+1, b) {
            int c = i - a - b;
            if (c < 0) continue;

            double p = cmb[i][a] * cmb[i-a][b] / pow(3.0, i);
            int cnt[3] = {a, b, c};
            sort(cnt, cnt+3);
            if (cnt[0] == cnt[2] || cnt[1] == 0) {
                p_d += p;
            } else {
                sum += p * (1 + E[cnt[cnt[0] == 0]]);
            }
        };
        E[i] = (p_d + sum) / (1 - p_d);
    }

    cout << setprecision(10) << fixed;
    cout << E[N] << endl;
    return 0;
}
