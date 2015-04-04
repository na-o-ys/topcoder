#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    int a, b; cin >> a >> b;
    char p[10];
    fill(p, p+10, 'x');
    loop (a+b, i) {
        int v; cin >> v;
        v = (v+9)%10;
        p[v] = i < a ? '.' : 'o';
    }
    int s = 6;
    for (int i = 4; i; i--) {
        loop (4-i, j) cout << " ";
        loop (i, j) cout << p[s+j] << " ";
        s -= i-1;
        cout << endl;
    }
    return 0;
}
