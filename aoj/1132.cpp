#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
typedef pair<double, double> P;
const double EPS = 1e-4;

#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;

vector<P> center(P a, P b)
{
    auto t = atan2(b.second - a.second, b.first - a.first);
    auto x = hypot(a.first - b.first, a.second - b.second) / 2;
    auto y = sqrt(1.0 - x * x);
    auto cs = cos(t), sn = sin(t);
    return { 
        { cs * x - sn * y + a.first, sn * x + cs * y + a.second },
        { cs * x + sn * y + a.first, sn * x - cs * y + a.second }
    };
}

int main()
{
    while (1) {
        int n; cin >> n;
        if (!n) break;
        vector<P> pnt;
        loop (n, i) {
            double x, y; cin >> x >> y;
            pnt.emplace_back(x, y);
        }
        int ans = 1;
        loop (n, i) loop (n, j) {
            auto ps = center(pnt[i], pnt[j]);
            for (auto o : ps) {
                int cnt = 0;
                loop (n, l) {
                    auto x = o.first - pnt[l].first;
                    auto y = o.second - pnt[l].second;
                    if (x * x + y * y < 1 + EPS) cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
