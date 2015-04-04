#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    int N; cin >> N;
    int C[100001] = {};
    loop (N, i) {
        int a; cin >> a;
        C[a]++;
    }

    ll M[100001] = {};
    M[1] = C[1];
    from_to(2, 100000, i) M[i] = max(M[i-2]+(ll)i*C[i], M[i-1]);
    cout << M[100000] << endl;
    return 0;
}
