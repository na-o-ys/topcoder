#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;

int main()
{
    double ans = 0;

    int N; cin >> N;
    loop (N, i) {
        double sc = 0;
        loop (4, j) {
            int v; cin >> v;
            sc += v;
        }
        int v; cin >> v;
        sc += 1.0 * v * 11/90;
        ans = max(ans, sc);
    }
    printf("%.12f\n", ans);
    return 0;
}
