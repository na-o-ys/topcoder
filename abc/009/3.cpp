#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)
#define repeat(n) for(int i__=0;i__<n;i__++)
#define each(itr, c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)
#define r_each(itr, c) for(__typeof((c).rbegin()) itr=(c).rbegin(); itr!=(c).rend(); itr++)

using namespace std;

int main(int argc, char const* argv[])
{
    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<int> chars(26, 0);
    for (auto&& c : s) chars[c-'a']++;

    string ans(n, '*');

    loop(n, i) {
        loop(26, j) {
            if (chars[j] == 0) continue;
            ans[i] = j+'a';

            int count = 0;
            loop(i+1, l) if (ans[l] != s[l]) count++;

            vector<int> tmp = chars;
            tmp[j]--;
            loop_from_to(i+1, n-1, l) {
                if (tmp[s[l]-'a']) tmp[s[l]-'a']--;
                else count++;
            }

            if (count > k) continue;
            chars[j]--;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}
