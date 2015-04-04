#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
typedef long long ll;
const double EPS = 1e-5;

int main()
{
    double x, y;  cin >> x >> y;
    int xk = floor(1000 * x + EPS), yk = floor(1000 * y + EPS);
    int x1 = x-1, y1 = y, x2 = x1, y2 = y1-1;
    int x1d = x1 - (xk - x1 * 1000);
    int y1d = y1 - (yk - y1 * 1000);
    int x2d = x2 - (xk - x2 * 1000);
    int y2d = y2 - (yk - y2 * 1000);
    printf("%d %d %d %d\n", x1, y1, x1d, y1d);
    printf("%d %d %d %d\n", x2, y2, x2d, y2d);
    return 0;
}
