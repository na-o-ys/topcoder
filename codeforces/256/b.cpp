#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    string s, t;
    cin >> s >> t;
    loop (26, i) {
        int cs[26] = {}, ct[26] = {};
        for (char c : s) cs[c-'a']++;
        for (char c : t) ct[c-'a']++;
        loop (26, i) {
            if (cs[i] != ct[i]) break;
            if (i == 25) {
                cout << "array" << endl;
                return 0;
            }
        }
    }
    loop (26, i) {
        int p = 0;
        loop (t.length(), q) {
            char c = t[q];
            while (p < s.length() && s[p] != c) p++;
            if (p == s.length()) break;
            if (q == t.length()-1) {
                cout << "automaton" << endl;
                return 0;
            }
            p++;
        }
    }
    loop (26, i) {
        int cs[26] = {}, ct[26] = {};
        for (char c : s) cs[c-'a']++;
        for (char c : t) ct[c-'a']++;
        loop (26, i) {
            if (cs[i] < ct[i]) break;
            if (i == 25) {
                cout << "both" << endl;
                return 0;
            }
        }
    }
    cout << "need tree" << endl;
    return 0;
}
