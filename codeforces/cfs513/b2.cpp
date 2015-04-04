#include <bits/stdc++.h>
 
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;

int main()
{
    int n;
    ll m;
    cin >> n >> m;
    vector<int> head, tail;
    for (int i = 1; i < n; i++) {
        if (m <= (1ll << n-i-1)) {
            head.push_back(i);
        } else {
            tail.push_back(i);
            m -= (1ll << n-i-1);
        }
    }
    head.push_back(n);

    for (int v : head) cout << v << " ";
    reverse(all(tail));
    for (int v : tail) cout << v << " ";
    cout << endl;
    return 0;
}
