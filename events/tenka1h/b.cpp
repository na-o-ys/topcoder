#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using P = pair<int, int>;
using ll = long long;

int main(int argc, char const* argv[])
{
    int N, M; cin >> N >> M;
    vector<P> s;
    loop (N, i) {
        int x, y; cin >> x >> y;
        s.emplace_back(x, y);
    }
    vector<set<P>> S(N);
    loop (N, i) loop (N, j) {
        if (i == j) continue;
        S[i].emplace(s[j].first - s[i].first, s[j].second - s[i].second);
    }

    vector<vector<P>> seiza(M);
    loop (M, i) {
        int l; cin >> l;
        int X, Y; cin >> X >> Y;
        loop (l-1, j) {
            int x, y; cin >> x >> y;
            seiza[i].emplace_back(x-X, y-Y);
        }
    }

    //loop (N, i) {
    //    for (P p : S[i]) cout << p.first << ", " << p.second << endl;
    //    cout << endl;
    //}

    //loop (M, i) {
    //    for (P p : seiza[i]) cout << p.first << ", " << p.second << endl;
    //    cout << endl;
    //}

    loop (M, i) {
        int cnt = 0;
        loop (N, j) {
            bool ok = true;
            for (P p : seiza[i]) if (!S[j].count(p)) ok = false;
            if (ok) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
