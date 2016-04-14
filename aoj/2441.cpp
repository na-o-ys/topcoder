#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;
const ll INF = 2e+18;

ll calc(ll v) {
    ll k[] = { 1, 2, 4, 7, 8, 11, 13, 14 };
    ll ans = 32 * v;
    if (ans < 0) return INF;
    loop (18, i) {
        ll base = pow(10, i);
        ll n = (base - 1) / 15;
        if (n >= v) break;
        ll m = 0;
        while (15 * n + k[m] < base) m++;
        ll nbase = base * 10;
        ll nn = min((nbase - 1) / 15, v - 1);
        if (i == 17) nn = v - 1;
        ll nm = 0;
        while (nm < 8 && 15 * nn + k[nm] < nbase) nm++;
        ll cnt = 0;
        if (n != nn) cnt = (nn - n - 1) * 8 + (8 - m) + nm;
        else cnt = nm - m;
        ans += cnt * (i + 1);
        if (ans < 0) return INF;
    }
    return ans;
}

int main()
{
    ll s; cin >> s;

    ll l = 0, r = (2e+18)/15;
    while (l + 1 < r) {
        ll m = (l + r) / 2;
        if (s <= calc(m)) r = m;
        else l = m;
    }
    string ans;
    for (int i = 1; i <= 30; i++) {
        if (i % 3 == 0) ans.append("Fizz");
        if (i % 5 == 0) ans.append("Buzz");
        if (i % 3 && i % 5) ans.append(to_string(i + 15 * l));
    }
    cout << ans.substr(s - calc(l) - 1, 20) << endl;
    return 0;
}
