#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int N, M, D;
vector<int> mult(vector<int> a, vector<int> b) {
    vector<int> ans(N+1);
    loop (N, i) ans[i+1] = b[a[i+1]];
    return ans;
}

int main(int argc, char const* argv[])
{
    cin >> N >> M >> D;
    int A[300000] = {};
    loop (M, i) cin >> A[i];
    vector<int> perm(N+1);
    loop (N, i) perm[i+1] = i+1;
    loop (M, i) swap(perm[A[M-1-i]], perm[A[M-1-i]+1]);

    vector<int> ans(N+1);
    loop (N, i) ans[i+1] = i+1;
    loop (31, i) {
        if ((D >> i) & 1) ans = mult(ans, perm);
        perm = mult(perm, perm);
    }

    loop (N, i) cout << ans[i+1] << endl;
    return 0;
}
