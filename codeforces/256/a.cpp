#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    int c = 0, m = 0;
    loop (3, i) {
        int a; cin >> a;
        c += a;
    }
    loop (3, i) {
        int b; cin >> b;
        m += b;
    }
    int n; cin >> n;
    if (((c+4)/5) + ((m+9)/10) > n) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}
