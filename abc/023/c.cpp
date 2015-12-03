#include <bits/stdc++.h>
#include <unordered_set>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main()
{
    int R, C, k, n; cin >> R >> C >> k >> n;
    vector<int> rows(R+10), cols(C+10);
    vector<int> rows_sum(100010);
    vector<P> S;
    loop (n, i) {
        int r, c; cin >> r >> c;
        S.emplace_back(--r, --c);
        rows[r]++;
        cols[c]++;
    }

    loop (R, i) rows_sum[rows[i]]++;

    ll ans = 0;
    loop (C, i) {
        if (cols[i] > k) continue;
        ans += rows_sum[k - cols[i]];
    }

    for (P p : S) {
        if (rows[p.first] + cols[p.second] == k) ans--;
        if (rows[p.first] + cols[p.second] -1 == k) ans++;
    }

    cout << ans << endl;
    return 0;
}
