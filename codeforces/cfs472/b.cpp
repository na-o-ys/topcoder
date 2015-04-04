#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    int n, k; cin >> n >> k;
    vector<int> F(n);
    loop (n, i) cin >> F[i];
    sort(F.begin(), F.end(), greater<int>());
    ll ans = 0;
    for (int i = 0; i < n; i += k) {
        ans += (F[i]-1)*2;
    }
    cout << ans << endl;
    return 0;
}
