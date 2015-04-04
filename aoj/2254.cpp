#include <bits/stdc++.h>
  
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
 
using namespace std;
const int INF = 1<<29;
 
int main()
{
    while (1) {
        int n; cin >> n;
        if (!n) break;
        int t[20][20];
        loop (n, i) loop (n+1, j) cin >> t[i][j];
        int cost[20][100000];
        loop (n+1, i) loop (2<<n, j) cost[i][j] = INF;
        loop (n, i) cost[1][1<<i] = t[i][0];
        loop (n+1, i) {
            loop (1<<n, j) {
                if (__builtin_popcount(j) != i) continue;
                loop (n, k) if (j>>k&1) {
                    int c = t[k][0];
                    loop (n, l) if (j>>l&1 && l != k) {
                        c = min(c, t[k][l+1]);
                    }
                    cost[i][j] = min(cost[i][j], cost[i-1][j^(1<<k)] + c);
                }
            }
        }
        cout << cost[n][(1<<n)-1] << endl;
    }
    return 0;
}
