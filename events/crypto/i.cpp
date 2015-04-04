#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    string s; cin >> s;
    string ans;
    int cnt = 0;
    char ch = 0;
    for (char c : s) {
        cnt++;
        if (!cnt) {
            ans += ch;
            ch = 0;
        }
        ch <<= 1;
        ch += c-'0';
    }

    return 0;
}
