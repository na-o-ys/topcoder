#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(int argc, char const* argv[])
{
    int n; cin >> n;
    vector<P> IN(n);
    loop (n, i) {
        int a, b; cin >> a >> b;
        IN[i] = P(a, b);
    }

    sort(IN.begin(), IN.end());
    int d = 0;
    for (P p : IN) {
        d = p.second >= d ? p.second : p.first;
    }
    cout << d << endl;
    return 0;
}
