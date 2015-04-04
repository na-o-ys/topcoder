#include <iostream>
 
using namespace std;

int solve(string s, string t)
{
    int i = 0;
    for (; i < t.length() && t[i] == t[0]; i++) {
        if (i >= s.length() || s[i] != t[i]) return 0;
    }
    int j = i;
    for (; i < s.length(); i++, j++) {
        while (j < t.length() && s[i] != t[j]) j++;
        if (j >= t.length()) return 0;
    }
    return 1;
}

int main()
{
    string s, t; cin >> s >> t;
    cout << (solve(s, t) ? "Yes" : "No") << endl;
    return 0;
}
