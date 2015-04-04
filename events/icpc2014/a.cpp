#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    int N, M; cin >> N >> M;
    vector<int> b(N), p(M);
    loop (N, i) cin >> b[i];
    loop (M, i) cin >> p[i];

    return 0;
}
