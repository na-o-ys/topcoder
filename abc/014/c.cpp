#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int C[1000002] = {};
int main(int argc, char const* argv[])
{
    int N; cin >> N;
    loop (N, i) {
        int a, b; cin >> a >> b;
        C[a] += 1;
        C[b+1] -= 1;
    }

    int ans = C[0];
    loop (1000000, i) {
        C[i+1] += C[i];
        ans = max(ans, C[i+1]);
    }
    cout << ans << endl;
    return 0;
}
