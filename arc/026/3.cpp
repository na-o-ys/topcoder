#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)
#define repeat(n) for(int i__=0;i__<n;i__++)

using namespace std;
using iii = tuple<int, int, int>;
using ll = long long;
const ll INF = 200000000000;

int main(int argc, char const* argv[])
{
    int N, L; cin >> N >> L;
    vector<iii> lights;
    loop(N, i) {
        int l, r, c; cin >> l >> r >> c;
        lights.emplace_back(l+1, r+1, c);
    }
    sort(lights.begin(), lights.end());

    vector<ll> dp(L+1, INF);
    dp[0] = 0;
    for (iii lt : lights) {
        int l = get<0>(lt);
        int r = get<1>(lt);
        int c = get<2>(lt);
        for (int ri = r-1; ri >= l; ri--) {
            if (dp[ri] <= dp[l-1]+c) break;
            dp[ri] = min(dp[ri], dp[l-1] + c);
        }
    }
    cout << dp[L] << endl;
    return 0;
}
