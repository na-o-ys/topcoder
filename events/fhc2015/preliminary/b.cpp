#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;

int main()
{
    int T; cin >> T;
    loop (T, cs) {
        int gp, gc, gf; cin >> gp >> gc >> gf;
        int N; cin >> N;
        vector<int> p(N), c(N), f(N);
        loop (N, i) cin >> p[i] >> c[i] >> f[i];
        bool ok = false;
        loop (1<<N, i) {
            int ap = 0, ac = 0, af = 0;
            loop (N, j) {
                if (i>>j & 1) {
                    ap += p[j];
                    ac += c[j];
                    af += f[j];
                }
            }
            if (ap == gp && ac == gc && af == gf) {
                ok = true;
                break;
            }
        }
        printf("Case #%d: %s\n", cs+1, (ok ? "yes" : "no"));
    }
    return 0;
}
