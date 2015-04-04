#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    string key[] = { "qwertyuiop", "asdfghjkl;", "zxcvbnm,./" };
    char d; cin >> d;
    int p = d == 'R' ? -1 : 1;
    string s; cin >> s;
    for (char c : s) {
        loop (3, i) loop (key[i].length(), j) {
            if (c == key[i][j]) cout << key[i][j+p];
        }
    }
    cout << endl;
    return 0;
}
