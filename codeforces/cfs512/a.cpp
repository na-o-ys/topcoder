#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;

int main()
{
    int N; cin >> N;
    int od[30][30] = {};
    string prev; cin >> prev;
    loop (N-1, n) {
        string crr; cin >> crr;
        int i = 0;
        while (min(prev.length(), crr.length()) > i && prev[i] == crr[i]) i++;
        if (i == crr.length() && prev.length() > crr.length()) return puts("Impossible");
        if (i == prev.length()) {
            prev = crr;
            continue;
        }
        int f = prev[i] - 'a';
        int l = crr[i] - 'a';
        prev = crr;
        od[f][l] = 1;
    }
    loop (26, k) loop (26, i) loop (26, j) od[i][j] |= od[i][k] && od[k][j];
    loop (26, i) if (od[i][i]) return puts("Impossible");

    vector<int> ok(26);
    while (1) {
        int done = 1;
        loop (26, i) if (!ok[i]) {
            int ng = 0;
            loop (26, j) if (!ok[j] && od[j][i]) ng = 1;
            if (!ng) {
                ok[i] = 1;
                cout << (char)('a' + i);
            }
            done = 0;
        }
        if (done) break;
    }
    cout << endl;
    return 0;
}
