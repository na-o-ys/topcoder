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
    string s; cin >> s;
    if (s[0] >= 'a') cout << (char)('A' + (s[0] - 'a'));
    else cout << s[0];

    loop(s.size()-1, i) {
        if (s[i+1] < 'a') cout << (char)('a' + (s[i+1] - 'A'));
        else cout << s[i+1];
    }
    cout << endl;
    return 0;
}
