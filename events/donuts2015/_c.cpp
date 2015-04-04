#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;

const int INF = 1<<29;

int main()
{
    int n; cin >> n;
    vector<int> H(n); loop (n, i) cin >> H[i];
    reverse(all(H));

    loop (n, i) {
        if (!i) {
            cout << 0 << endl;
            continue;
        }
        vector<int> dp(i, INF);
        for (int j = n-i; j < n; ++j) {
            *lower_bound(all(dp), H[j]) = H[j];
        }
        cout << distance(dp.begin(), lower_bound(all(dp), INF)) << endl;
    }
    return 0;
}
