#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int gcd(int n, int m) {
    if (m == 0) return n;
    return gcd(m, n%m);
}

bool disj(int r, vector<int> s) {
    for (int m : s) if (gcd(r, m) != 1) return false;
    return true;
}

int main(int argc, char const* argv[])
{
    int n, k;
    cin >> n >> k;// n = 10000;
    vector<vector<int>> S(n);
    int odd = 1;
    loop (n, i) {
        loop (3, j) {
            S[i].push_back(odd);
            odd += 2;
        }
    }
    int r = 0;
    for (auto& s : S) {
        r += 2;
        while (!disj(r, s)) r += 2;
        s.push_back(r);
    }
    odd -= 2;
    cout << odd*k << endl;
    for (auto s : S) {
        for (int v : s) cout << v*k << " ";
        cout << endl;
    }
    return 0;
}
