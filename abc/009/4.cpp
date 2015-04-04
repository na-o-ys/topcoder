#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)
#define repeat(n) for(int i__=0;i__<n;i__++)
#define each(itr, c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)
#define r_each(itr, c) for(__typeof((c).rbegin()) itr=(c).rbegin(); itr!=(c).rend(); itr++)

using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

vec mult(mat const &mat, vec const &v) {
    int m = mat.size();
    int n = mat[0].size();
    vec ans(m, 0);
    loop(m, i)  loop(n, j) ans[i] ^= mat[i][j] & v[j];
    return ans;
}

mat mult(mat const &a, mat const &b) {
    int l = a.size();
    int m = a[0].size();
    int n = b[0].size();
    mat ans(l, vec(n, 0));

    loop(l, i) loop(n, j) loop(m, k) ans[i][j] ^= a[i][k] & b[k][j];
    return ans;
}

mat pow(mat a, int p) {
    int m = a[0].size();
    mat ans(m, vec(m, 0));
    loop(m, i) ans[i][i] = -1;

    for (; p; p >>= 1) {
        if (1&p) ans = mult(ans, a);
        a = mult(a, a);
    }
    return ans;
}

int main(int argc, char const* argv[])
{
    ll k, p;
    cin >> k >> p;
    ll a[k];
    loop(k, i) cin >> a[i];
    ll c[k];
    loop(k, i) cin >> c[i];

    mat M(k, vec(k, 0));
    loop(k, i) M[0][i] = c[i];
    loop(k-1, i) M[i+1][i] = -1;

    reverse(a, a+k);
    vec init(a, a+k);

    M = pow(M, p-1);
    vec ans = mult(M, init);
    cout << ans[k-1] << endl;

    return 0;
}
