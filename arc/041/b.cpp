#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

int main()
{
    int N, M; cin >> N >> M;
    int b[501][501] = {};
    loop (N, i) {
        string l; cin >> l;
        loop (M, j) b[i][j] = l[j]-'0';
    }

    int ans[501][501] = {};
    loop (N, i) {
        loop (M, j) {
            if (b[i][j] > 0) {
                ans[i+1][j] += b[i][j];
                b[i+1][j-1] -= b[i][j];
                b[i+1][j+1] -= b[i][j];
                b[i+2][j] -= b[i][j];
            }
        }
    }

    loop (N, i) {
        loop (M, j) cout << ans[i][j];
        cout << endl;
    }
    return 0;
}
