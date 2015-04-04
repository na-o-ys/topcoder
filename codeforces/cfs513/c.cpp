#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> l(n), r(n);
    loop (n, i) cin >> l[i] >> r[i];
    double ans = 0;

    loop (n, snd) for (int v = l[snd]; v <= r[snd]; v++) {
        loop (n, fst) if (fst != snd) {
            double prod = 1.0 / (r[snd] - l[snd] + 1);

            loop (n, i) if (i != snd) {
                // Pr(price[i] < v)  for i < snd
                // Pr(price[i] <= v) for i > snd
                int right = min(r[i], v - (i < snd));
                double x = max(right - l[i] + 1, 0);
                double p_lt = x / (r[i] - l[i] + 1);
                prod *= (i == fst ? 1.0 - p_lt : p_lt);
            }

            ans += prod * v;
        }
    }
    printf("%.12f\n", ans);
    return 0;
}
