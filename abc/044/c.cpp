#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

int X[100], n;
ll memo[60][60][3000];
ll rec(int i, int r, int sum) {
    if (r == 0 && sum == 0) return 1;
    if (i >= n || r < 0 || sum < 0) return 0;
    if (memo[i][r][sum] != -1) return memo[i][r][sum];
    return memo[i][r][sum] = rec(i + 1, r, sum) + rec(i + 1, r - 1, sum - X[i]);
}

int main()
{
    fill(memo[0][0], memo[59][59]+3000, -1);
    int a; cin >> n >> a;
    loop (n, i) cin >> X[i];

    ll ans = 0;
    loop (n, i) {
        ans += rec(0, i + 1, a * (i + 1));
    }
    cout << ans << endl;
    return 0;
}
