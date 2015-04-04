#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

struct line { double x1, y1, x2, y2; };
bool intersect(line l1, line l2) {
    double a = (l1.x1-l1.x2)*(l2.y1-l1.y1) + (l1.y1-l1.y2)*(l1.x1-l2.x1);
    double b = (l1.x1-l1.x2)*(l2.y2-l1.y1) + (l1.y1-l1.y2)*(l1.x1-l2.x2);
    double c = (l2.x1-l2.x2)*(l1.y1-l2.y1) + (l2.y1-l2.y2)*(l2.x1-l1.x1);
    double d = (l2.x1-l2.x2)*(l1.y2-l2.y1) + (l2.y1-l2.y2)*(l2.x1-l1.x2);
    return (a*b < 0) && (c*d < 0);
}

int main(int argc, char const* argv[])
{
    double ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    line L { ax, ay, bx, by };
    int n; cin >> n;
    vector<double> x(n), y(n);
    loop (n, i) cin >> x[i] >> y[i];
    vector<line> ls;
    int cnt = 0;
    loop (n, i) {
        line l { x[i], y[i], x[(i+1)%n], y[(i+1)%n] };
        if (intersect(L, l)) cnt++;
    }
    cout << cnt/2 + 1 << endl;
    return 0;
}
