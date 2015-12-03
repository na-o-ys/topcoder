#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

int main()
{
    int n, d, k; cin >> n >> d >> k;
    vector<int> l(d), r(d), s(k), t(k), ans(k);
    loop (d, i) cin >> l[i] >> r[i];
    loop (k, i) cin >> s[i] >> t[i];

    loop (d, i) {
        loop (k, j) {
            if (l[i] <= s[j] && s[j] <= r[i]) {
                if (s[j] < t[j]) {
                    s[j] = min(t[j], r[i]);
                } else {
                    s[j] = max(t[j], l[i]);
                }
            }
            if (s[j] == t[j] && ans[j] == 0) {
                ans[j] = i+1;
            }
        }
    }

    loop (k, i) cout << ans[i] << endl;
    return 0;
}
