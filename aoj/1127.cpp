#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;
struct Elem {
    int to;
    double cost;
};

bool operator >(const Elem& x, const Elem& y) {
    return tie(x.cost, x.to) > tie(y.cost, y.to);
}

int main()
{
    while (1) {
        int n; cin >> n;
        if (!n) break;
        vector<double> x(n), y(n), z(n), r(n);
        loop (n, i) cin >> x[i] >> y[i] >> z[i] >> r[i];
        vector<vector<double>> dist(n, vector<double>(n));
        loop (n, i) loop (n, j) {
            double d = pow(
                    pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2) + pow(z[i] - z[j], 2),
                    0.5
                    );
            dist[i][j] = max(0.0, d - r[i] - r[j]);
        }

        priority_queue<Elem, vector<Elem>, greater<Elem>> Q;
        vector<int> vis(n);
        Q.push({ 0, 0 });
        double ans = 0;
        while (Q.size()) {
            Elem e = Q.top(); Q.pop();
            if (vis[e.to]) continue;
            vis[e.to] = 1;
            ans += e.cost;
            loop (n, i) if (i != e.to && !vis[i]) {
                Q.push({ i, dist[e.to][i] });
            }
        }
        cout << setprecision(3) << fixed << ans << endl;
    }
    return 0;
}
