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
    vector<int> T(N);
    loop (N, i) cin >> T[i];
    sort(T.begin(), T.end(), greater<int>());
    int a = 0, b = 0;
    for (int t : T) {
        if (a < b) a += t;
        else b += t;
    }
    cout << max(a, b) << endl;
    return 0;
}
