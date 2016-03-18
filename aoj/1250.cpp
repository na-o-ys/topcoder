#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

int main()
{
    int n; cin >> n;
    while (n--) {
        vector<ll> e(9);
        loop (9, i) {
            string s; cin >> s;
            e[i] = stoll(s, nullptr, 16) % (1ll<<32);
        }
        ll ans = 0;
        loop (32, i) {
            ll sum = 0;
            ll mask = (1 << i) - 1;
            loop (8, j) sum += ans ^ (mask & e[j]);
            loop (8, j) sum ^= e[j];
            sum &= (1ll << i);
            ans |= (sum ^ (e[8] & (1ll << i)));
        }
        cout << hex << ans << endl;
    }
    return 0;
}
