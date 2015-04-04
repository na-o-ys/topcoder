#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;

int main()
{
    int x, y, r; cin >> x >> y >> r;
    x = abs(x);
    y = abs(y);
    double d = r / sqrt(2);
    cout << ceil(2 * d + x + y) << endl;
    return 0;
}
