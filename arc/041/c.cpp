#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

int main()
{
    int N, L; cin >> N >> L;
    ll x[100010] = {};
    char d[100010] = {};
    loop (N, i) cin >> x[i] >> d[i];
    x[N] = L + 1;

    ll ans = 0;
    int idx = 0;
    // 最初の左を処理
    while (idx < N && d[idx] == 'L') idx++;
    loop (idx, i) {
        ans += x[i]-1-i;
    }

    // N の場合

    while (idx < N) {
        // 右の右端
        int idxr = idx;
        while (idxr < N && d[idxr] == 'R') idxr++;
        // 左の右端
        int idxl = idxr;
        while (idxl < N && d[idxl] == 'L') idxl++;

        // 右の個数
        int cntr = idxr - idx;
        // 左の個数
        int cntl = idxl - idxr;

        // 右を右詰め
        loop (cntr-1, i) ans += x[idxr - 1] - x[idxr - 1 - (i + 1)] - 1 - i;

        // 左を左詰め
        loop (cntl-1, i) ans += x[idxl - 1 - i] - x[idxr] - 1 - i;

        // 中間の空白
        ll sp = x[idxr] - x[idxr-1] - 1;
        ans += sp * max(cntr, cntl);
        idx = idxl;
    }

    cout << ans << endl;

    return 0;
}
