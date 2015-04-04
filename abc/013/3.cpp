#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    ll N, H; cin >> N >> H;
    ll A, B, C, D, E; cin >> A >> B >> C >> D >> E;

    ll ans = 1LL<<55;
    loop (N+1, i) {
        ll p = (N-i)*E - H + 1;
        if (B*i < p) continue;
        ll d = (B*i-p)/(B-D);
        if (d > i) d = i;
        ans = min(ans, d*C + (i-d)*A);
    }
    cout << ans << endl;

    return 0;
}
