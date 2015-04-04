#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    ll n, l, x, y; cin >> n >> l >> x >> y;
    vector<ll> a(n);
    loop (n, i) cin >> a[i];
    int xok = 0, yok = 0;
    for (ll v : a) {
        xok = xok || binary_search(a.begin(), a.end(), x+v);
        yok = yok || binary_search(a.begin(), a.end(), y+v);
    }

    if (!xok && !yok) {
        for (ll v : a) {
            loop (2, i) {
                int X, Y;
                if (i) X = x, Y = y;
                else X = y, Y = x;
                for (int pm : {1, -1}) {
                    ll add = v+pm*X;
                    if (add < 0 || add > l) continue;
                    if (binary_search(a.begin(), a.end(), add-Y) || 
                            binary_search(a.begin(), a.end(), add+Y)) {
                        cout << 1 << endl << add << endl;
                        return 0;
                    }

                }
            }
        }
    }
    cout << 2-xok-yok << endl;
    vector<ll> vs;
    if (!xok) vs.push_back(x);
    if (!yok) vs.push_back(y);
    for (ll v : vs) cout << v << " ";
    if (vs.size()) cout << endl;
    return 0;
}
