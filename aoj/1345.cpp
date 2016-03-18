#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

int main()
{
    int n, m; cin >> n >> m;
    vector<int> T(n);
    vector<vector<int>> S(2);
    loop (n, i) cin >> T[i];
    loop (m, i) {
        int v; cin >> v;
        loop (v, j) {
            S[0].push_back(i%2);
            S[1].push_back((i+1)%2);
        }
    }

    int ans = 1<<29;
    loop (2, i) {
        int tpop = 0, spop = 0;
        for (int v : T) tpop += v;
        for (int v : S[i]) spop += v;
        if (tpop != spop) continue;

        int c = tpop < (n - tpop);
        int ti = 0, si = 0, cnt = 0;
        while (ti < n && si < n) {
            while (ti < n && T[ti] != c) ti++;
            while (si < n && S[i][si] != c) si++;
            cnt += abs(ti - si);
            ti++, si++;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
