#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    ll n; cin >> n;
    ll left = 1, right = 2^40;
    ll k = 1;
    for (;; k++) {
        ll cards = 2*k + 3*k*(k-1)/2;
        if (cards > n) break;
    }
    k--;
    for (; k >= 0; k--) {
        ll cards = 2*k + 3*k*(k-1)/2;
        if (cards%3 == n%3) break;
    }
    if (k <= 0) cout << 0 << endl;
    else cout << 1 + (k-1)/3 << endl;
    return 0;
}
