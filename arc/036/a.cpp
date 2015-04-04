#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;

int main()
{
    int N; cin >> N;
    vector<int> h(N);
    loop (N, i) cin >> h[i];
    int ans = 0;
    int asc = 1;
    int len = 1;
    for (int i = 1; i < h.size(); i++) {
        int d = h[i] - h[i-1];
        if (asc) {
            if (d < 0) asc = 0;
        } else {
            if (d > 0) {
                ans = max(len, ans);
                len = 1;
                asc = 1;
            }
        }
        len++;
    }
    cout << max(len, ans) << endl;
    return 0;
}
