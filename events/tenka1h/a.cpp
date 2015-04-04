#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

const int MOD = 1000000007;
//ll calc(int h, int n, int w) {
//    ll ans = 0;
//    loop (n, i) {
//        ans = (ans + cmb(w, i) * calc(h-1, n, w-i)) % MOD;
//    }
//}

int pow(int a, int b) {
    if (b == 0) return 1;
    return a * pow(a, b-1);
}
int main(int argc, char const* argv[])
{
    int h, n, w; cin >> h >> n >> w;
    if (w > 5 || h > 40 || n > 5) return 0;
    int ans = 0;
    for (int i = pow(h, w-1); i < pow(h, w); i++) {
        int I = i;
        vector<int> cnt(h);
        loop (w, j) {
            cnt[I%h]++;
            I /= h;
        }
        bool ok = true;
        for (int c : cnt) if (c > n) ok = false;
        if (ok) ans++;
    }
    cout << ans << endl;
    return 0;
}
