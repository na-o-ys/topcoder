#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
typedef long long ll;
const ll MAX = 10000000000;

void Main(int n, int k, int *a) {
    ll ans = MAX;
    int count = 0;
    loop(n, i) loop_from_to(i+1, n-1, j) {
        ll v = abs((ll)a[i] + a[j] - k);
        if (v == ans) count++;
        else if (v < ans) { ans = v; count = 1; }
    }
    cout << ans << " " << count << endl;
}

int main(int argc, char const* argv[])
{
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        int a[n]; loop(n, i) cin >> a[i];
        Main(n, k, a);
    }
  return 0;
}
