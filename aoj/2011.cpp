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
DONE:
        int n; cin >> n;
        if (!n) break;
        vector<vector<int>> sch(n);
        loop (n, i) {
            int k; cin >> k;
            vector<int> s(k);
            loop (k, j) cin >> s[j];
            sch[i] = s;
        }

        vector<unordered_set<int>> maps(n);
        loop (30, i) {
            int day = i+1;
            vector<int> fnd;
            loop (n, j) {
                int ok = 0;
                for (int d : sch[j]) if (d == day) ok = 1;
                if (ok) fnd.push_back(j);
            }
            for (int f : fnd) {
                for (int t : fnd) {
                    maps[f].insert(t);
                    for (int v : maps[t]) {
                        maps[f].insert(v);
                    }
                }
            }
            for (auto s : maps) {
                if (s.size() == n) {
                    cout << day << endl;
                    goto DONE;
                }
            }
        }
        cout << -1 << endl;
    }
    return 0;
}
