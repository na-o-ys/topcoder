#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)

using namespace std;

vector<string> S;

int dfs(string s, bool lose = 0) {
    int l = s.length();

    auto p = lower_bound(S.begin(), S.end(), s);
    if (p == S.end() || (*p).length() < l || (*p).substr(0, l) != s) {
        return 2;
    }
    if (*p == s && (next(p) == S.end() || ((*next(p)).substr(0, l) != s))) {
        return (l%2);
    }

    bool b = ((l%2) == 0) ^ lose;
    loop (26, i) {
        int d = dfs(s + (char)('a'+i));
        if (d == 2) continue;
        if (d == b) return b;
    }
    return !b;
}

int main(int argc, char const* argv[])
{
    int n, k; cin >> n >> k;
    S = vector<string>(n);
    loop (n, i) cin >> S[i];
    sort(S.begin(), S.end());

    cout << dfs("") << !dfs("", 1) << endl;
    bool first = dfs("") && (!dfs("", 1) || (k%2));
    string ans = first ? "First" : "Second";
    cout << ans << endl;
    return 0;
}

