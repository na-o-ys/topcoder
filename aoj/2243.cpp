#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

int main()
{
    while (1) {
        string S; cin >> S;
        if (S == "#") break;

        int ans = 1<<19;
        loop (2, i) {
            int p[2] = { 1, 3 };
            int l = i, cnt = 0;
            for (char c : S) {
                int v = (c - '1') % 3 + 1;
                int f = (l * 2) - 1;
                if (f * (v - p[l^1]) >= 0) {
                    p[l] = v;
                    l ^= 1;
                } else {
                    p[l^1] = v;
                    cnt++;
                }
            }
            ans = min(ans, cnt);
        }
        cout << ans << endl;
    }
    return 0;
}
