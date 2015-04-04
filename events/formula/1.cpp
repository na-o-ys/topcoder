#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    int a; cin >> a;
    from_to(1, 10001, i) {
        if (a == i*i*i) {
            cout << "YES" << endl;
            return 0;
        }
        if (a < i*i*i) break;
    }
    cout << "NO" << endl;
    return 0;
}

