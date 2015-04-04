#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
 
using namespace std;
using ll = long long;
using ld = long double;
 
ld perm(int m, int n)
{
    if (!n) return 1;
    return perm(m-1, n-1) * m;
}
 
ld cmb(int m, int n)
{
    return perm(m, n) / perm(n, n);
}
 
int main()
{
    cout << setprecision(10) << fixed;
    ld dp[101] = {};
    dp[2] = 1.5l;
    // loop (100, i) {
    //     ld orig = dp[3];
    //     dp[3] = 1.0l/3 * (1 + dp[3]) + 2.0l/3;
    //     cout << orig-dp[3] << endl;
    // }
    for (int i = 3; i <= 100; i++) {
        loop (100, l) {
            ld draw = 3;
            if (i%3 == 0) draw += cmb(i, i/3) * cmb(i/3*2, i/3);
            dp[i] = draw * (1 + dp[i]);
 
            for (int j = 1; j < i; j++) {
                ld v = 0;
                if (j*2 < i) v += cmb(i, j) * 3 * 2;
                for (int k = j+1; j < i-k-j && k < i-k-j; k++) {
                    v += cmb(i, j) * cmb(i-j, k) * 3 * 2;
                }
                if (j*3 < i) v += cmb(i, j) * cmb(i-j, j) * 3;
                dp[i] += v * (1 + dp[j]);
            }
 
            dp[i] /= pow(3.0l, i);
        }
    }
 
    int n;
    cin >> n;
    cout << dp[n] << endl;
    return 0;
}
