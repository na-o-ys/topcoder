#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)
#define repeat(n) for(int i__=0;i__<n;i__++)
#define each(itr, c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)
#define r_each(itr, c) for(__typeof((c).rbegin()) itr=(c).rbegin(); itr!=(c).rend(); itr++)

using namespace std;
using ll = long long;

double cmb(int m, int n) {
    if ((m^n) == 0) return 1;
    if (n == 0) return cmb(m-1, 0) / 2;
    return cmb(m, n-1) * (m-n+1) / n;
}

double prob(int x, int i) {
    if (x > i || (x^i)&1) return 0;
    int l = (i-x)/2;
    return cmb(i, l);
}

int main(int argc, char const* argv[])
{
    int N, D, X, Y; cin >> N >> D >> X >> Y;
    if (X % D || Y % D) { cout << 0 << endl; return 0; }
    
    X = abs(X);
    Y = abs(Y);
    X /= D; Y /= D;

    double ans = 0;
    loop(N+1, i) ans += cmb(N, i) * prob(X, i) * prob(Y, N-i);
    cout << ans << endl;
    return 0;
}
