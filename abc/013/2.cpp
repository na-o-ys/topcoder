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
    cout << min(abs(b-a), 10-abs(b-a)) << endl;
    return 0;
}
