#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    string str;
    getline(cin, str);
    int cs[26] = {};
    for (char c : str) {
        if (c < 'a' || c > 'z') continue;
        cs[c - 'a'] = 1;
    }
    int ans = 0;
    loop(26, i) if (cs[i]) ans++;
    cout << ans << endl;
    return 0;
}
