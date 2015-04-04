#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(int argc, char const* argv[])
{
    int n, m; cin >> n >> m;
    unordered_map<ll, P> mp;
    ll gt = 10000000;
    while (n--) {
        int id, attr, val, pri;
        cin >> id >> attr >> val >> pri;
        auto v = mp[id*gt + attr];
        if (v.first <= pri) mp[id*gt + attr] = P(pri, val);
    }

    while (m--) {
        int id, attr; cin >> id >> attr;
        cout << mp[id*gt + attr].second << endl;
    }
    return 0;
}
