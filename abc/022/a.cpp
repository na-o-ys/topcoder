#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
typedef long long ll;

int main()
{
    int n, s, t; cin >> n >> s >> t;
    int a[1010] = {};
    cin >> a[0];
    loop (n-1, i) cin >> a[i+1];
    loop (n-1, i) a[i+1] += a[i];
    int cnt = 0;
    loop (n, i) if (a[i] >= s && a[i] <= t) cnt++;
    cout << cnt << endl;
    return 0;
}
