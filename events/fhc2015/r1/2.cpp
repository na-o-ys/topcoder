#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    int T; cin >> T;
    loop (T, t) {
        int N; cin >> N;
        set<string> S;
        int ans = 0;
        while (N--) {
            string word; cin >> word;
            int l = 0, r = word.size()+1;
            while (l < r-1) {
                int mid = (l+r)/2;
                string pref = word.substr(0, mid);
                auto p = S.lower_bound(pref);
                if (p == S.end() || (*p).substr(0, mid) != pref) r = mid;
                else l = mid;
            }
            ans += min(r, (int)word.size());
            // int len = 1;
            // for (; len < word.size(); len++) {
            //     string pref = word.substr(0, len);
            //     auto p = lower_bound(all(S), pref);
            //     if (p == S.end() || (*p).substr(0, len) != pref) break;
            // }
            // ans += len;
            S.insert(word);
        }
        printf("Case #%d: %d\n", t+1, ans);
    }
    return 0;
}
