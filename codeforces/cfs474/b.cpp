#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    int n; cin >> n;
    int a[1000010] = {};
    int s = 0;
    loop (n, i) {
        int t; cin >> t; a[s += t] = 1;
    }
    loop (1000009, i) {
        a[i+1] += a[i];
    }

    int m; cin >> m;
    loop (m, i) {
        int q; cin >> q;
        cout << a[q-1]+1 << endl;
    }
    return 0;
}
