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

int main(int argc, char const* argv[])
{
    ll N; cin >> N;
    ll ans = 0;
    for (ll i = 1; i*i <= N; i++) {
        if (N % i == 0) {
            if (i*i == N) ans += i;
            else ans += i + N/i;
        }
    }
    ans -= N;
    if (ans < N) cout << "Deficient";
    else if (ans == N) cout << "Perfect";
    else cout << "Abundant";
    cout << endl;
    return 0;
}
