#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;

int gcd(int m, int n)
{
    if (!n) return m;
    return gcd(n, m%n);
}

int main()
{
    int n; cin >> n;
    vector<int> l(n), c(n);
    loop (n, i) cin >> l[i];
    loop (n, i) cin >> c[i];

    unordered_map<int, int> mp;
    mp[l[0]] = c[0];
    loop (n-1, i) {
        //cout << "****" << i+1 << "****" << endl;
        unordered_map<int, int> _mp = mp;
        if (_mp.count(l[i+1])) {
            _mp[l[i+1]] = min(c[i+1], _mp[l[i+1]]);
        } else _mp[l[i+1]] = c[i+1];
        for (auto&& e : mp) {
            //cout << e.first << " " << e.second << endl;
            int g = gcd(e.first, l[i+1]);
            int cost = e.second + c[i+1];
            if (_mp.count(g)) cost = min(cost, _mp[g]);
            _mp[g] = cost;
        }
        mp = _mp;
    }
    if (mp.count(1)) cout << mp[1] << endl;
    else cout << -1 << endl;
    return 0;
}
