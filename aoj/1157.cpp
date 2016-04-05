#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

struct Vec { double x, y, z; };

Vec operator+(const Vec& a, const Vec& b) {
    return { a.x + b.x, a.y + b.y, a.z + b.z };
}

Vec operator-(const Vec& a, const Vec& b) {
    return { a.x - b.x, a.y - b.y, a.z - b.z };
}

Vec operator*(const Vec& a, const double v) {
    return { a.x * v, a.y * v, a.z * v };
}

double operator*(const Vec& a, const Vec& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

double abs(Vec v) {
    return pow(v * v, 0.5);
}

Vec nearest(Vec s, Vec t, Vec p) {
    Vec normed_l = (t - s) * (1.0 / abs(t - s));
    double cap = normed_l * (t - s);
    double a = normed_l * (p - s);
    if (a < 0) return s;
    if (a > cap) return t;
    return s + (normed_l * a);
}

double EPS = 1e-8;
double INF = 1<<29;
double dist(Vec s, Vec t, vector<vector<Vec>> ps) {
    double ans = INF;
    for (auto p : ps) {
        vector<Vec> ck = p;
        ck.push_back(nearest(p[0], p[1], s));
        ck.push_back(nearest(p[0], p[1], t));
        ck.push_back(nearest(p[0], p[2], s));
        ck.push_back(nearest(p[0], p[2], t));
        ck.push_back(nearest(p[1], p[3], s));
        ck.push_back(nearest(p[1], p[3], t));
        ck.push_back(nearest(p[2], p[3], s));
        ck.push_back(nearest(p[2], p[3], t));
        for (Vec v : ck) {
            Vec boal = nearest(s, t, v);

            double l = 0, r = 2000;
            while (l + EPS < r) {
                double m = (l + r) / 2;
                Vec center = { boal.x, boal.y, m };
                Vec vs = { v.x, v.y, 0 };
                Vec p = nearest(vs, v, center);
                if (m < abs(p - center)) l = m;
                else r = m;
            }
            ans = min(ans, l);
        }
    }
    return ans;
}

int main()
{
    while (1) {
        int n; cin >> n;
        if (!n) break;

        Vec s, t; cin >> s.x >> s.y >> t.x >> t.y;
        s.z = 0, t.z = 0;
        vector<vector<Vec>> ps;
        while (n--) {
            vector<Vec> p;
            double x[2], y[2], h;
            cin >> x[0] >> y[0] >> x[1] >> y[1] >> h;
            loop (2, i) loop (2, j) p.push_back({ x[i], y[j], h });
            ps.push_back(p);
        }
        cout << dist(s, t, ps) << endl;
    }
    return 0;
}
