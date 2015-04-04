#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;
const int INF = 1 << 28;

int main(int argc, char const* argv[])
{
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        int m1 = INF, m2 = INF;
        while(N--) {
            int a; cin >> a;
            if (a < m1) { m2 = m1; m1 = a; }
            else if (a < m2) m2 = a;
        }
        cout << m1 + m2 << endl;
    }
    return 0;
}
