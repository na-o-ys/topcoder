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
        vector<int> sum(n+10);
        loop (n, i) {
            int p = min((m - H[i] + S[i] - 1) / S[i], (ll)n);
            p = max(p, 0);
            sum[p]++;
        }

        int ok = 1;
        loop (n, i) {
            sum[i+1] += sum[i];
            //INSP(i+1);
            //INSP(sum[i+1]);
            if (sum[i+1] > i+1) ok = 0;
        }

        if (ok) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << l << endl;
    return 0;
}
