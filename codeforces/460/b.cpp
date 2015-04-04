#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int sum(int n) {
    if (!n) return 0;
    return (n%10) + sum(n/10);
}

ll pow(int a, int b) {
    if (b == 0) return 1;
    return (ll)a * pow(a, b-1);
}

int main(int argc, char const* argv[])
{
    int a, b, c; cin >> a >> b >> c;
    vector<int> ans;
    from_to (1, 100, s) {
        ll x = b * pow(s, a) + c;
        if (x < 1000000000 && x > 0 && sum(x) == s) ans.push_back(x);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;;
    if (ans.size()) {
        bool b = true;
        for (int c : ans) {
            if (!b) cout << " ";
            cout << c;
            b = false;
        }
        cout << endl;
    }
    return 0;
}
