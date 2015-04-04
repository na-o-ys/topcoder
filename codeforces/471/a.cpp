#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    int v[10] = {};
    loop (6, i) { int l; cin >> l; v[l]++; }
    bool ok = false;
    loop (10, i) if (v[i] >= 4) { ok = true; v[i] -= 4; }
    if (!ok) { cout << "Alien" << endl; return 0; }
    loop (10, i) if (v[i] >= 2) { cout << "Elephant" << endl; return 0; }
    cout << "Bear" << endl;
    return 0;
}
