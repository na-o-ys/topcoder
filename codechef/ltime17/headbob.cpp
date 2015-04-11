#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    int t; cin >> t;
    vector<string> out;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int chk = 0;
        for (char c : s) {
            if (c == 'Y') chk = 1;
            if (c == 'I') chk = 2;
        }
        switch (chk) {
            case 0:
                out.push_back("NOT SURE"  );
                break;
            case 1:
                out.push_back("NOT INDIAN");
                break;
            case 2:
                out.push_back("INDIAN"    );
                break;
        }
    }
    for (auto s : out) cout << s << endl;
    return 0;
}
