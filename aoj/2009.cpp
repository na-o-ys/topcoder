#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

struct P { double x, y; };
P operator+(const P& a, const P& b) { return { a.x+b.x, a.y+b.y }; }
P operator-(const P& a, const P& b) { return { a.x-b.x, a.y-b.y }; }
P operator*(const P& a, const double& v) { return { a.x*v, a.y*v }; }
double cross(P a, P b) { return a.x * b.y - a.y * b.x; }
P intersection(P a1, P a2, P b1, P b2) {
    P a = a2-a1, b = b2-b1;
    return a1 + a * (cross(b, b1-a1) / cross(b, a));
}

const double EPS = 1e-10;

int main()
{
    while (1) {
        int n; cin >> n;
        if (!n) break;
        int ans = 1;
        vector<vector<P>> ls;
        while (n--) {
            P a, b;
            cin >> a.x >> a.y >> b.x >> b.y;
            vector<P> ps;
            for (auto l : ls) {
                P c = l[0], d = l[1];
                P t = intersection(a, b, c, d);
                if (t.x >= -100 + EPS && t.x <= 100 - EPS &&
                    t.y >= -100 + EPS && t.y <= 100 - EPS) {
                    int ok = 1;
                    for (P p : ps) {
                        if (sqrt(pow(p.x-t.x, 2) + pow(p.y-t.y, 2)) < EPS) ok = 0;
                    }
                    if (ok) {
                        ps.push_back(t);
                        ans++;
                    }
                }
            }
            ans += 1;
            ls.push_back({ a, b });
        }
        cout << ans << endl;
    }
    return 0;
}
