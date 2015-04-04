#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;
const int MAX = 100001;
int TBL[MAX][MAX] = {};

int main(int argc, char const* argv[])
{
    int N; cin >> N;
    vector<int> A(N);
    loop (N, i) cin >> A[i];
    int M; cin >> M;
    if (N <= 100)
    {
        loop (M, i) {
            int t; cin >> t;
            if (t == 1) {
                int l, r, p; cin >> l >> r >> p;
                from_to(l-1, r-1, j) if (A[j]%p == 0) A[j] /= p;
            } else {
                int l, d; cin >> l >> d;
                A[l-1] = d;
            }
        }
        for (int a : A) cout << a << " ";
        cout << endl;
    }
    else {
        vector<vector<int>> Q(6, vector<int>(N+1));
        loop (M, i) {
            int t; cin >> t;
            if (t == 1) {
                int l, r, p; cin >> l >> r >> p;
                Q[p][l-1]++;
                Q[p][r]--;
            }
            else { int l, d; cin >> l >> d; }
        }
        for (int p : {2, 3, 5}) {
            int acc = 0;
            loop (N, i) {
                acc += Q[p][i];
                loop (acc, j) {
                    if (A[i]%p) break;
                    A[i] /= p;
                }
            }
        }
        for (int a : A) cout << a << " ";
        cout << endl;
    }
    return 0;
}
