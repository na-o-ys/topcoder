#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

int N;
int memo[11][2];

ll count(int dd, int f) {
    if (dd == 0) return 0;
    if (memo[dd][f] != -1) return memo[dd][f];
    if (f) {
        int v = (N / (int)pow(10, dd-1)) % 10;
        int ans = 0;
        if (v >= 1) ans += count(dd-1, 0) * v;
        if (v > 1) ans += pow(10, dd-1);
        // 上限
        ans += count(dd-1, 1);
        if (v == 1) ans += (N % (int)pow(10, dd-1)) + 1;
        memo[dd][f] = ans;
    } else {
        if (dd == 1) {
            memo[dd][f] = 1;
        } else {
            memo[dd][f] = count(dd-1, 0) * 10 + pow(10, dd-1);
        }
    }

    return memo[dd][f];
}

int main()
{
    cin >> N;
    int d = 0, t = 1;
    ll ans = 0;
    while (t <= N) t *= 10, d += 1;
    fill(memo[0], memo[10]+2, -1);

    cout << count(d, 1) << endl;

    return 0;
}
