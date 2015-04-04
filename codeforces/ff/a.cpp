#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    int n; cin >> n;
    int a[100010] = {}, fwd[100010] = {}, bck[100010] = {};
    loop (n, i) cin >> a[i+1];
    loop_from_to (1, n, i) {
        if (a[i-1] < a[i]) fwd[i] = fwd[i-1]+1;
        else fwd[i] = 1;
    }
    a[n+1] = 1<<30;
    for (int i = n; i; i--) {
        if (a[i] < a[i+1]) bck[i] = bck[i+1]+1;
        else bck[i] = 1;
    }
    int ans = 0;
    a[0] = -1;
    loop_from_to (1, n, i) {
        if (a[i-1]+1 < a[i+1]) ans = max(ans, fwd[i-1] + bck[i+1] + 1);
        else ans = max(ans, max(fwd[i-1]+1, bck[i+1]+1));
    }
    // loop_from_to (1, n, i) {
    //     cout << fwd[i] << " ";
    // }
    // cout << endl;
    // loop_from_to (1, n, i) {
    //     cout << bck[i] << " ";
    // }
    // cout << endl;
    cout << ans << endl;
    return 0;
}
