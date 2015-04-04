#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;
using ld = long double;

int main(int argc, char const* argv[])
{
    ld a, b; cin >> a >> b;
    if (a > b) swap(a, b);
    int n; cin >> n;
    loop (n, i) {
        ld c, d; cin >> c >> d;
        if (c > d) swap(c, d);
        if (c >= a && d >= b) { cout << "YES" << endl; continue; }
        if (a*a + b*b <= c*c) { cout << "YES" << endl; continue; }
        if (c < a) { cout << "NO" << endl; continue; }
        ld r = sqrt(a*a + b*b);
        ld t = acos(c/r) + asin(a/r);
        if (b*sin(t) + a*cos(t) <= d) { cout << "YES" << endl; continue; }
        cout << "NO" << endl;
    }
    return 0;
}
