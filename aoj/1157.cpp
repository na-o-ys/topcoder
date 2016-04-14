#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

const double INF = 1<<29;
const double EPS = 1e-8;

struct Vec { double x, y, z; };
Vec operator+(const Vec& a, const Vec& b) {
    return { a.x + b.x, a.y + b.y, a.z + b.z };
}
Vec operator-(const Vec& a, const Vec& b) {
    return { a.x - b.x, a.y - b.y, a.z - b.z };
}
Vec operator*(const Vec& v, double n) {
    return { v.x * n, v.y * n, v.z * n };
}
double operator*(const Vec& a, const Vec& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
double abs(const Vec& v) {
    return pow(v * v, 0.5);
}

double dist_l2p(Vec a, Vec b, Vec p) {
    Vec l = (b - a) * (1.0 / abs(b - a));
    double len = l * (p - a);
    if (len < 0) return abs(a - p);
    if (len > abs(b - a)) return abs(b - p);
    return abs((l * len) - (p - a));
}

double dist_l2l(Vec a1, Vec a2, Vec b1, Vec b2) {
    double l = 0, r = 1;
    while (l + EPS < r) {
        double m = (l + r) / 2;
        double v1 = dist_l2p(a1, a2, b1 + ((b2 - b1) * m));
        double v2 = dist_l2p(a1, a2, b1 + ((b2 - b1) * (m + EPS)));
        if (v1 < v2) r = m;
        else l = m;
    }
    return dist_l2p(a1, a2, b1 + ((b2 - b1) * l));
}

double dist(Vec s, Vec t, Vec a, Vec b, double h) {
    double d = dist_l2l(s, t, a, b);
    if (d < h) return d;
    a.z = h, b.z = h;
    double l = d, r = 2000;
    while (l + EPS < r) {
        double m = (l + r) / 2;
        s.z = m, t.z = m;
        if (m < dist_l2l(s, t, a, b)) l = m;
        else r = m;
    }
    return l;
}

int main()
{
    while (1) {
        int n; cin >> n;
        if (!n) break;
        Vec s, t;
        cin >> s.x >> s.y >> t.x >> t.y;
        s.z = 0, t.z = 0;
        double ans = INF;
        while (n--) {
            Vec a, b, c, d;
            double h;
            cin >> a.x >> a.y >> c.x >> c.y >> h;
            b.x = a.x, b.y = c.y, d.x = c.x, d.y = a.y;
            a.z = b.z = c.z = d.z = 0;
            if (a.x < min(s.x, t.x) && a.y < min(s.y, t.y) && c.x > max(s.x, t.x) && c.y > max(s.y, t.y)) ans = 0;
            ans = min(ans, dist(s, t, a, b, h));
            ans = min(ans, dist(s, t, b, c, h));
            ans = min(ans, dist(s, t, c, d, h));
            ans = min(ans, dist(s, t, d, a, h));
        }
        cout << setprecision(8) << fixed << ans << endl;
    }
    return 0;
}
