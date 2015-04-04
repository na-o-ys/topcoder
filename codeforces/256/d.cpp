#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    int n, m, k;
    cin >> n >> m >> k;
    int l = 0, r = n*m;
    while (r-l > 1) {
        int v = (l+r)/2;
        int s = 0;
        loop (n, i) s += min(m, v/(i+1));
        if (s >= k) r = v;
        else l = v;
    }
    cout << r << endl;
    return 0;
}
