#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> A(N);
        loop (N, i) cin >> A[i];
        int M; cin >> M;

        if (N > 100) {
            vector<int> F(N-1);
            loop (N-1, i) if (A[i] != A[i+1]) F[i]++;
            loop (N-2, i) F[i+1] += F[i];

            while (M--) {
                int t, l, r; cin >> t >> l >> r;
                if (t == 1) {
                    l--; r--;
                    int fr = r == 0 ? 0 : F[r-1]; 
                    int fl = l == 0 ? 0 : F[l-1];
                    int f = fr - fl + 1;
                    cout << f << endl;
                }
            }
            continue;
        }

        while (M--) {
            int t, l, r; cin >> t >> l >> r;
            l--; r--;
            if (t == 1) {
                int f = 1;
                from_to (l, r-1, i) if (A[i] != A[i+1]) f++;
                cout << f << endl;
            } else {
                vector<int> tmp(r-l+1);
                loop (r-l+1, i) tmp[i] = A[l+i];
                loop (l, i) A[r-i] = A[l-1-i];
                loop (r-l+1, i) A[i] = tmp[i];
            }
        }
    }
    return 0;
}
