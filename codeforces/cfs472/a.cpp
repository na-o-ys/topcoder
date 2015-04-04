#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    int n; cin >> n;
    for (int a = 4;; a++) {
        int b = n - a;
        bool ok = false;
        for (int i = 2; i*i <= a; i++) {
            if (a%i == 0) ok = true;
        }
        if (!ok) continue;
        ok = false;
        for (int i = 2; i*i <= b; i++) {
            if (b%i == 0) ok = true;
        }
        if (!ok) continue;
        cout << a << " " << b << endl;
        break;
    }
    return 0;
}
