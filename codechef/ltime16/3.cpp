#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;
const int MAX = 100001;
int Q[3][MAX][MAX] = {};

int main(int argc, char const* argv[])
{
    int N; cin >> N;
    vector<int> A(N);
    loop (N, i) cin >> A[i];

    int mp[6] = {};
    mp[3] = 1; mp[5] = 2;

    int M; cin >> M;
    loop (M, i) {
        int t; cin >> t;
        if (t == 1) {
            int l, r, p; cin >> l >> r >> p;
            Q[mp[p]][i][l-1]++;
            Q[mp[p]][i][r]--;
        }
        else { int l, d; cin >> l >> d; }
    }

    for (int p : {2, 3, 5}) {
        loop (N, i) Q[m]
    }

    for (int p : {2, 3, 5}) {
        int acc = 0;
        loop (N, i) {
            acc += Q[mp[p]][i];
            loop (acc, j) {
                if (A[i]%p) break;
                A[i] /= p;
            }
        }
    }
    for (int a : A) cout << a << " ";
    cout << endl;
    return 0;
}
