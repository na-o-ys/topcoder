#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

int main()
{
    int q; cin >> q;
    ll cnt[2] = {};
    while (q--) {
        ll p, n;
        char c;
        cin >> p >> c >> n;
        cnt[c-'('] += n;
        if (cnt[0] == cnt[1]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
