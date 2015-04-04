#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<ll> A(N);
        loop (N, i) cin >> A[i];
        sort(A.begin(), A.end(), greater<ll>());
        bool turn = 1;
        ll ans = 0;
        for (ll a : A) {
            if (turn) ans += a;
            turn ^= 1;
        }
        cout << ans << endl;
    }
    return 0;
}
