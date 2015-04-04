#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    int n, m; cin >> n >> m;
    int ans = 0;
    while (n) {
        ans++;
        n--;
        if (ans%m == 0) n++;
    }
    cout << ans << endl;
    return 0;
}
