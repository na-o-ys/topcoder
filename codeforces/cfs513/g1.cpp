#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;

int main()
{
    int n, k; cin >> n >> k;
    vector<int> p(n);
    loop (n, i) cin >> p[i];

    loop (n, l) loop (n, r) {
        if (r <= l) continue;
        vector<int> P = p;
        loop ((r-l)/2 + 1, i) swap(P[l+i], P[r-i]);
    }
    return 0;
}
