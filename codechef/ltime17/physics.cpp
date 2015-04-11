#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    int t; cin >> t;
    while (t--) {
        int n, f; cin >> n >> f;
        unordered_map<int, int> mp;
        loop (n, i) {
            int h; cin >> h;
            while (h%f == 0) h /= f;
            mp[h]++;
        }
        ll ans = 0;
        for (auto m : mp) {
            ans += (m.second * (m.second-1))/2;
        }
        cout << ans << endl;
    }
    return 0;
}
