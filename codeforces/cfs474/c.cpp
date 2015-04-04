#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    int n; cin >> n;
    int x[100][4], y[100][4], a[100][4], b[100][4];
    loop (n, i) {
        loop (4, j) {
            cin >> x[i][j] >> y[i][j] >> a[i][j] >> b[i][j];
        }
    }

    loop (n, i) {
        int ans = 5;
        loop (256, j) {
            int X[4], Y[4];
            int cnt = 0;
            loop (4, k) {
                X[k] = x[i][k];
                Y[k] = y[i][k];
                loop (((j>>(k*2))&3), l) {
                    int tX = -Y[k]+a[i][k]+b[i][k];
                    int tY = X[k]-a[i][k]+b[i][k];
                    X[k] = tX; Y[k] = tY;
                    cnt++;
                }
            }

            bool ok = true;
            loop (4, p) loop (4, q) {
                if (p == q) continue;
                if (X[p] == X[q] && Y[p] == Y[q]) ok = false;
            }
            loop (4, p) {
                vector<int> d;
                loop (4, q) {
                    if (p == q) continue;
                    int dx = X[q]-X[p], dy = Y[q]-Y[p];
                    d.push_back(dx*dx+dy*dy);
                }
                sort(d.begin(), d.end());
                if (!(d[0] == d[1] && d[0]*2 == d[2])) ok = false;
            }
            if (ok) ans = min(ans, cnt);
        }
        if (ans == 5) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}
