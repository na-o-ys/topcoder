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
    vector<ll> H(n), S(n);
    loop (n, i) {
        cin >> H[i] >> S[i];
    }

    ll l = 0, r = 1LL<<62;
    while (l + 1 < r) {
        ll m = (l + r) / 2;
        vector<ll> t(n);
        int ok = 1;
        loop (n, i) {
            if (m - H[i] < 0) ok = 0;
            t[i] = (m - H[i]) / S[i];
        }
        sort(all(t));

        loop (n, i) {
            if (t[i] < i) ok = 0;
        }

        if (ok) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << r << endl;
    return 0;
}
