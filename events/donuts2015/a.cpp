#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;
constexpr double PI = asin(1)*2;

int main()
{
    int r, d; cin >> r >> d;
    double ans = r * r * PI * 2 * PI * d;
    printf("%.9f\n", ans);
    return 0;
}
