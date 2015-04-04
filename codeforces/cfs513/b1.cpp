#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;

int main()
{
    int n, m; cin >> n >> m;
    vector<int> p; loop (n, i) p.push_back(i+1);
    vector<vector<int>> ps;
    int mv = 0;
    do {
        int v = 0;
        loop (n, i) {
            int Min = 1<<29;
            for (int j = i; j < n; j++) {
                Min = min(Min, p[j]);
                v += Min;
            }
        }
        if (mv < v) {
            mv = v;
            ps = {p};
        } else if (mv == v) ps.push_back(p);
    } while (next_permutation(all(p)));
    cout << mv << endl;
    cout << ps.size() << endl;
    loop (n, i) cout << ps[m-1][i] << " ";
    cout << endl;
    return 0;
}
