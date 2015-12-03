#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

int main()
{
    int N = 2000010;
    int n, t; cin >> n >> t;
    int d[N] = {};
    loop (n, i) {
        int a; cin >> a;
        d[a] += 1;
        d[a + t] -= 1;
    }

    int ans = 0;
    loop (N-1, i) {
        d[i+1] += d[i];
        if (d[i+1] > 0) ans++;
    }

    cout << ans << endl;

    return 0;
}
