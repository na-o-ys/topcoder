#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1000000007;

int main()
{
    int a, b; cin >> a >> b;
    ll ans = 1;
    unordered_map<int, int> mp;
    for (int i = b+1; i <= a; i++) {
        int v = i;
        for (int j = 2; j * j <= v; j++) {
            int cnt = 0;
            while (v % j == 0) { v /= j; cnt++; }
            if (cnt) mp[j] += cnt;
        }
        if (v > 1) mp[v] += 1;
    }

    for (P p : mp) {
        ans = ans * (p.second + 1) % MOD;
    }
    cout << ans << endl;
    return 0;
}
