#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

int main()
{
    int a, b, c; cin >> a >> b >> c;
    int t = 0;
    int vis[60] = {};
    while (1) {
        int mt = t % 60;
        if (mt <= c && mt + a >= c) {
            cout << t - mt + c << endl;
            break;
        }
        if (vis[mt]) {
            cout << -1 << endl;
            break;
        }
        vis[mt] = 1;
        t += a + b;
    }
    return 0;
}
