#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    while (n--) {
        int h, w; cin >> h >> w;
        vector<string> B(h);
        loop (h, i) cin >> B[i];

        unordered_set<char> alphs;
        loop (h, i) loop (w, j) {
            char c = B[i][j];
            if (c != '.') alphs.insert(c);
        }
        vector<char> perm(all(alphs));
        sort(all(perm));
        int safe = 0;
        do {
            map<char, int> layer = {{ '.', 0 }};
            loop (perm.size(), i) layer[perm[i]] = i+1;

            for (char c : perm) {
                int l = 100, r = 0, t = 100, b = 0;
                loop (h, i) loop (w, j) if (B[i][j] == c) {
                    l = min(j, l);
                    r = max(j, r);
                    t = min(i, t);
                    b = max(i, b);
                }
                for (int i = t; i <= b; i++) {
                    for (int j = l; j <= r; j++) {
                        if (layer[B[i][j]] < layer[c]) goto NG;
                    }
                }
            }
            safe = 1;
            break;
NG:
            continue;
        } while (next_permutation(all(perm)));
        if (safe) cout << "SAFE" << endl;
        else cout << "SUSPICIOUS" << endl;
    }
    return 0;
}
