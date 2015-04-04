#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(ll i=0;i<n;i++)
#define from_to(from, to, i) for(ll i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    ll l, r, k; cin >> l >> r >> k;
    ll S = 1LL << 60, L, K;

    from_to (1, min(10LL, k), i) {
        from_to (l, min(r-i+1, l+100), j) {
            ll sum = 0;
            from_to (j, j+i-1, l) sum ^= l;
            if (sum < S) {
                S = sum;
                L = j;
                K = i;
            }
        }
    }

    if (S != 0 && k == 3) {
        if ((r >= (r & -r)+1) && l <= (r & -r)-2) {
            cout << 0 << endl;
            cout << 3 << endl;
            cout << (r & -r)-2 << " " << (r & -r)-1 << " " << (r & -r)+1 << endl;
            return 0;
        }; 
        ll p = (r&-r);
        p = p>>1;
        
        if ((r >= (r & -r)+1) && l <= (r & -r)-2) {
            cout << 0 << endl;
            cout << 3 << endl;
            cout << (r & -r)-2 << " " << (r & -r)-1 << " " << (r & -r)+1 << endl;
            return 0;
        }; 
    }

    cout << S << endl;
    cout << K << endl;
    loop (K, i) cout << L+i << " ";
    cout << endl;
    return 0;
}
