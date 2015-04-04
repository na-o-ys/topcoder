#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;

int main()
{
    string s; cin >> s;
    loop (s.length(), i) {
        if (s[i] == '*') s[s.length()-1-i] = '*';
    }
    string ss = s;
    reverse(all(ss));
    cout << (ss == s ? "YES" : "NO") << endl;
    return 0;
}
