#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

int main()
{
    while (1) {
        int n, t, l, b; cin >> n >> t >> l >> b;
        if (!n) break;

        vector<int> type(n+1);
        loop (l, i) {
            int j; cin >> j;
            type[j] = 1;
        }
        loop (b, i) {
            int j; cin >> j;
            type[j] = 2;
        }

        vector<vector<double>> prob(t+1, vector<double>(n+1));
        vector<vector<double>> lprob(t+1, vector<double>(n+1));
        prob[0][0] = 1;

        loop (t, i) {
            loop (n, j) {
                if (type[j] == 1) {
                    lprob[i+1][j] += prob[i][j] * 6;
                }
                loop (6, k) {
                    int idx = j+k+1;
                    if (idx > n) idx = n - (idx - n);
                    if (type[idx] == 2) idx = 0;
                    double p = prob[i][j];
                    if (type[j] == 1) p = lprob[i][j];
                    prob[i+1][idx] += p;
                }
            }
            prob[i+1][n] += prob[i][n] * 6;
        }

        double ans = 0;
        double sum = 0;
        loop (n+1, j) sum += prob[t][j] + lprob[t][j];
        ans += prob[t][n] / sum;
        cout << setprecision(9) << fixed;
        cout << ans << endl;
    }
    return 0;
}
