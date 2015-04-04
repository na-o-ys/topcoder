#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    string s; cin >> s;
    int add; cin >> add;
    int l = s.length();
    int ans = 0;
    loop(l, i) {
        loop_from_to(1, l, j) {
            bool ok = true;
            loop(j, k) {
                if (i+j+k >= l) break;
                if (s[i+k] != s[i+j+k]) ok = false;
            }
            if (ok && i+j+j > l+add) ok = false;
            if (ok) ans = max(ans, j*2);
        }
    }
    cout << ans << endl;
    return 0;
}
