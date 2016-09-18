#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;
typedef pair<double, double> P;
const double EPS = 1e-12;

int main()
{
    int n, k; cin >> n >> k;
    vector<P> W;
    loop (n, i) {
        double w, p;
        cin >> w >> p;
        W.emplace_back(p, w);
    }

    sort(all(W), greater<P>());

    double l = 0, r = 100;
    while (l + EPS < r) {
        int cnt = 0;
        double m = (l + r) / 2;
        double t_s = 0, t_w = 0;
        vector<int> used(n);
        while (1) {
            int found = 0;
            loop (n, i) {
                double p = W[i].first, w = W[i].second;
                if (!used[i] && (t_s + w * p) / (t_w + w) >= m) {
                    cnt++;
                    used[i] = 1;
                    found = 1;
                    t_s += w * p;
                    t_w += w;
                    break;
                }
            }
            if (cnt == k || !found) break;
        }
        if (cnt == k) l = m;
        else r = m;
    }
    cout << setprecision(12) << l << endl;
    return 0;
}
