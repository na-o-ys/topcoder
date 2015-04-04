#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    int N, X, Y; cin >> N >> X >> Y;
    vector<int> A(N), B(N), Z(N);
    loop (N, i) cin >> A[i];
    loop (N, i) cin >> B[i];

    int tt = 0, cnt = 0;
    loop (N, i) {
        Z[i] = A[i] - B[i];
        if (Z[i] > 0) cnt++;
        tt += max(A[i], B[i]);
    }
    sort(Z.begin(), Z.end());
    auto p = upper_bound(Z.begin(), Z.end(), 0);
    if (cnt > X) {
        for (int i = 0; i < cnt-X; i++, p++) tt -= *p;
    } else if (N-cnt > Y) {
        p--;
        for (int i = 0; i < (N-cnt)-Y; i++, p--) tt += *p;
    }

    cout << tt << endl;
    return 0;
}
