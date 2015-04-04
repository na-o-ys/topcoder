#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;
const ll MOD = 1000000007;

int N;
string S;
vector<string> T;
ll memo[1001];
ll count(int len) {
    if (memo[len] >= 0) return memo[len];
    ll ret = 0;
    for (auto& s : T) {
        if (S.substr(len, s.length()) == s) {
            ret = (ret + count(len + s.length())) % MOD;
        }
    }
    return memo[len] = ret;
}

int main(int argc, char const* argv[])
{
    cin >> N;
    cin >> S;
    T = vector<string>(N);
    for (auto& s : T) cin >> s;
    fill(memo, memo+1001, -1);
    memo[S.length()] = 1;

    cout << count(0) << endl;
    return 0;
}
