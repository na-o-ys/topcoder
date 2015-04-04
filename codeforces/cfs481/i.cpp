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
    vector<int> p(n);
    loop (n, i) cin >> p[i];
    sort(p.begin(), p.end());
    int i = 0;
    for (; i < n-1; i++) {
        p[n-1] -= p[i];
        if (p[n-1] < 0) break;
    }
    cout << i+1 << endl;
    return 0;
}
